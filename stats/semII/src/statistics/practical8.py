from math import sqrt

from data import load_sample


def practical8(sample=None, seed=67):
    sample = load_sample() if sample is None else sample
    pair = sample[["Age", "weight"]].dropna().sample(n=50, random_state=seed)
    rho = pair["Age"].rank(method="average").corr(pair["weight"].rank(method="average"))
    t = rho * sqrt((len(pair) - 2) / (1 - rho**2))
    print("\nPractical 8: Spearman rank correlation")
    print(f"n=50, rho={rho:.6f}, t={t:.4f}, "
          f"significant at 5%={'yes' if abs(t) > 2.0106 else 'no'}")