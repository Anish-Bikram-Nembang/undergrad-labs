from pathlib import Path

import matplotlib.pyplot as plt

from data import load_data, load_sample


def practical5(sample=None, output_dir="outputs"):
    full = load_data()
    sample = load_sample() if sample is None else sample
    output = Path(output_dir)
    output.mkdir(parents=True, exist_ok=True)
    figure, axes = plt.subplots(1, 2, figsize=(12, 6))
    axes[0].boxplot(full["weight"].dropna())
    axes[0].set_title("Weight: complete data")
    axes[0].set_ylabel("Weight")
    groups = [group["weight"].dropna() for _, group in sample.groupby("typeofrespondent")]
    labels = [str(label) for label in sample.groupby("typeofrespondent").groups]
    axes[1].boxplot(groups, tick_labels=labels)
    axes[1].set_title("Weight by respondent type: sample")
    axes[1].set_ylabel("Weight")
    axes[1].tick_params(axis="x", rotation=30)
    figure.tight_layout()
    path = output / "practical5_boxplots.png"
    figure.savefig(path, dpi=150)
    plt.close(figure)
    print(f"\nPractical 5: box plots saved to {path}")