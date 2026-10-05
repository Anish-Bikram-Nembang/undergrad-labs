"""Poisson distribution fitted to the supplied discrete data."""

from math import exp, factorial


def practical8():
    x_values = list(range(9))
    frequencies = [60, 81, 92, 104, 78, 61, 55, 40, 29]
    total = sum(frequencies)
    mean = sum(x * frequency for x, frequency in zip(x_values, frequencies)) / total
    probabilities = [
        exp(-mean) * mean**x / factorial(x)
        for x in x_values
    ]
    expected = [total * probability for probability in probabilities]

    print("\nPractical 8:")
    print(f"Fitted Poisson distribution: lambda = {mean:.6f}")
    print("  x       P(x)       F(x)  Expected frequency")
    cumulative = 0
    for x, probability, expected_frequency in zip(x_values, probabilities, expected):
        cumulative += probability
        print(f"{x:3d}  {probability:9.6f}  {cumulative:9.6f}  {expected_frequency:17.4f}")
    print(f"P(X > 4) = {1 - sum(probabilities[:5]):.6f}")
    print(f"P(X < 4) = {sum(probabilities[:4]):.6f}")
    print(f"P(X = 4) = {probabilities[4]:.6f}")
