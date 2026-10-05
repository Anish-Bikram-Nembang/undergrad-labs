"""Normal distribution fitted to grouped data."""

from math import erf, sqrt


def _normal_cdf(value, mean, standard_deviation):
    z = (value - mean) / (standard_deviation * sqrt(2))
    return (1 + erf(z)) / 2


def practical9():
    classes = [(20, 30), (30, 40), (40, 50), (50, 60),
               (60, 70), (70, 80), (80, 90), (90, 100)]
    frequencies = [3, 13, 29, 37, 28, 15, 11, 4]
    midpoints = [(lower + upper) / 2 for lower, upper in classes]
    total = sum(frequencies)
    mean = sum(frequency * midpoint for frequency, midpoint
               in zip(frequencies, midpoints)) / total
    variance = sum(
        frequency * (midpoint - mean) ** 2
        for frequency, midpoint in zip(frequencies, midpoints)
    ) / total
    standard_deviation = sqrt(variance)

    def interval_probability(lower, upper):
        return (_normal_cdf(upper, mean, standard_deviation)
                - _normal_cdf(lower, mean, standard_deviation))

    probabilities = [interval_probability(*interval) for interval in classes]

    print("\nPractical 9:")
    print(f"Fitted normal distribution: mean = {mean:.6f}, "
          f"SD = {standard_deviation:.6f}")
    print("Class       P(class)  Expected frequency")
    for interval, probability in zip(classes, probabilities):
        print(f"{interval[0]:3d}-{interval[1]:<3d}  {probability:9.6f}"
              f"  {total * probability:17.4f}")
    print(f"P(30 < X < 70) = {interval_probability(30, 70):.6f}")
    print(f"P(X > 60) = {1 - _normal_cdf(60, mean, standard_deviation):.6f}")
    print(f"P(X < 80) = {_normal_cdf(80, mean, standard_deviation):.6f}")
