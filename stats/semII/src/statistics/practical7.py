from math import atanh, sqrt, tanh

from data import load_data, load_sample


def practical7(sample=None):
    full = load_data()
    sample = load_sample() if sample is None else sample
    print("\nPractical 7: Karl Pearson correlation")
    for name, data in (("given data", full), ("sample of 500", sample)):
        pair = data[["Age", "weight"]].dropna()
        n = len(pair)
        r = pair["Age"].corr(pair["weight"])
        t = r * sqrt((n - 2) / (1 - r**2))
        margin = 1.96 / sqrt(n - 3)
        z = atanh(r)
        print(f"{name}: n={n}, r={r:.6f}, t={t:.4f}, "
              f"significant at 5%={'yes' if abs(t) > 1.96 else 'no'}, "
              f"95% CI=({tanh(z - margin):.6f}, {tanh(z + margin):.6f})")