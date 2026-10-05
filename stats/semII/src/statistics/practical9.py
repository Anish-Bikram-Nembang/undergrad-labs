from pathlib import Path

import matplotlib.pyplot as plt

from data import load_sample


def practical9(sample=None, output_dir="outputs", seed=67):
    sample = load_sample() if sample is None else sample
    pair = sample[["Age", "weight"]].dropna().sample(n=50, random_state=seed)
    x, y = pair["Age"].to_numpy(), pair["weight"].to_numpy()
    x_bar, y_bar = x.mean(), y.mean()
    sxx = ((x - x_bar) ** 2).sum()
    slope = ((x - x_bar) * (y - y_bar)).sum() / sxx
    intercept = y_bar - slope * x_bar
    fitted = intercept + slope * x
    residuals = y - fitted
    sse = (residuals**2).sum()
    standard_error = (sse / (len(x) - 2)) ** 0.5
    r_squared = 1 - sse / ((y - y_bar) ** 2).sum()
    slope_se = standard_error / sxx**0.5
    t = slope / slope_se
    output = Path(output_dir)
    output.mkdir(parents=True, exist_ok=True)
    figure, axis = plt.subplots(figsize=(8, 6))
    axis.scatter(x, y, label="Sample (n=50)")
    order = x.argsort()
    axis.plot(x[order], fitted[order], color="tab:red",
              label=f"y = {intercept:.3f} + {slope:.3f}x, R²={r_squared:.3f}")
    axis.set_xlabel("Age")
    axis.set_ylabel("Weight")
    axis.set_title("Weight on age regression")
    axis.legend()
    figure.tight_layout()
    path = output / "practical9_regression.png"
    figure.savefig(path, dpi=150)
    plt.close(figure)
    print("\nPractical 9: regression of weight on age")
    print(f"Equation: weight = {intercept:.6f} + {slope:.6f} * age")
    print(f"Regression coefficient SE = {slope_se:.6f}, t = {t:.4f}, "
          f"significant at 5%={'yes' if abs(t) > 2.0106 else 'no'}")
    print(f"Standard error of estimate = {standard_error:.6f}")
    print(f"Coefficient of determination R² = {r_squared:.6f}")
    print(f"Residual mean = {residuals.mean():.6f}")
    print(f"Residual SD = {residuals.std(ddof=2):.6f}")
    print(f"Residual range = ({residuals.min():.6f}, {residuals.max():.6f})")
    print(f"Scatter plot saved to {path}")
