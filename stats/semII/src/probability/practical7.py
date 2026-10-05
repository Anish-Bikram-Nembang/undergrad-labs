"""Binomial distribution fitted to the supplied discrete data."""

from math import comb


def practical7():
    x_values = list(range(9))
    frequencies = [17, 22, 32, 45, 56, 41, 39, 20, 15]
    n = 8
    total = sum(frequencies)
    mean = sum(x * frequency for x, frequency in zip(x_values, frequencies)) / total
    p = mean / n
    q = 1 - p

    probabilities = [
        comb(n, x) * p**x * q ** (n - x)
        for x in x_values
    ]
    expected = [total * probability for probability in probabilities]

    print("\nPractical 7:")
    print(f"Fitted binomial distribution: n = {n}, p = {p:.6f}, q = {q:.6f}")
    print("  x       P(x)       F(x)  Expected frequency")
    cumulative = 0
    for x, probability, expected_frequency in zip(x_values, probabilities, expected):
        cumulative += probability
        print(f"{x:3d}  {probability:9.6f}  {cumulative:9.6f}  {expected_frequency:17.4f}")
    print(f"P(X >= 6) = {sum(probabilities[6:]):.6f}")
