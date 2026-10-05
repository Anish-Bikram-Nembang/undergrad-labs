"""Negative exponential distribution fitted to grouped decay times."""

from math import exp


def practical10():
    classes = [(0, 0.5), (0.5, 1.0), (1.0, 1.5), (1.5, 2.0), (2.0, 2.5)]
    frequencies = [86, 57, 34, 20, 13]
    midpoints = [(lower + upper) / 2 for lower, upper in classes]
    total = sum(frequencies)
    mean = sum(frequency * midpoint for frequency, midpoint
               in zip(frequencies, midpoints)) / total
    theta = mean

    def interval_probability(lower, upper):
        return exp(-lower / theta) - exp(-upper / theta)

    probabilities = [interval_probability(*interval) for interval in classes]

    print("\nPractical 10:")
    print(f"Fitted exponential distribution: theta = {theta:.6f}")
    print("Class       P(class)  Expected frequency")
    for interval, probability in zip(classes, probabilities):
        print(f"{interval[0]:3.1f}-{interval[1]:<3.1f}  {probability:9.6f}"
              f"  {total * probability:17.4f}")
    print(f"P(0.5 < X < 2.0) = {interval_probability(0.5, 2.0):.6f}")
    print(f"P(X > 1.5) = {exp(-1.5 / theta):.6f}")
    print(f"P(X < 1.0) = {1 - exp(-1.0 / theta):.6f}")
