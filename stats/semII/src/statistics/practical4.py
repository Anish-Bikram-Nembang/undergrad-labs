from data import load_sample
from statistics.practical1 import make_bins


def practical4(sample=None):
    sample = load_sample() if sample is None else sample
    age = sample["Age"].dropna()
    bins = make_bins(age)
    frequencies = [
        ((age >= lower) & (age < upper)).sum()
        for lower, upper in zip(bins[:-1], bins[1:])
    ]
    midpoints = [(lower + upper) / 2 for lower, upper in zip(bins[:-1], bins[1:])]
    total = sum(frequencies)
    mean = sum(f * x for f, x in zip(frequencies, midpoints)) / total
    moments = [
        sum(f * (x - mean) ** power for f, x in zip(frequencies, midpoints)) / total
        for power in range(1, 5)
    ]
    variance, mu3, mu4 = moments[1:]
    sd = variance**0.5
    print("\nPractical 4: grouped-data measures")
    print(f"Mean = {mean:.4f}")
    print(f"Variance = {variance:.4f}")
    print(f"SD = {sd:.4f}")
    print(f"Skewness = {mu3 / sd**3:.4f}")
    print(f"Kurtosis = {mu4 / variance**2:.4f}")