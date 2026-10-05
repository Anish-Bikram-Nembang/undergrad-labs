"""Charts for the age frequency distribution."""

from pathlib import Path

import matplotlib.pyplot as plt

from data import load_sample
from statistics.practical1 import make_bins


def practical3(sample=None, output_dir="outputs"):
    sample = load_sample() if sample is None else sample
    age = sample["Age"].dropna()
    bins = make_bins(age)
    output = Path(output_dir)
    output.mkdir(parents=True, exist_ok=True)

    class_labels = [
        f"{lower:g}-{upper:g}"
        for lower, upper in zip(bins[:-1], bins[1:])
    ]
    class_counts = [
        ((age >= lower) & (age < upper)).sum()
        for lower, upper in zip(bins[:-1], bins[1:])
    ]
    counts = age.groupby(age, observed=True).size()
    figure, axes = plt.subplots(2, 2, figsize=(12, 9))
    axes[0, 0].bar(counts.index, counts.values, width=0.8)
    axes[0, 0].set_title("Age bar diagram")
    axes[0, 0].set_xlabel("Age")
    axes[0, 0].set_ylabel("Frequency")

    axes[0, 1].pie(class_counts, labels=class_labels, autopct="%1.1f%%")
    axes[0, 1].set_title("Age pie chart by class interval")

    axes[1, 0].hist(age, bins=bins, edgecolor="black")
    axes[1, 0].set_title("Age histogram")
    axes[1, 0].set_xlabel("Age")
    axes[1, 0].set_ylabel("Frequency")

    sorted_age = age.sort_values()
    cumulative = sorted_age.reset_index(drop=True)
    axes[1, 1].plot(cumulative.index + 1, cumulative, drawstyle="steps-post")
    median = age.median()
    mode = age.mode().iloc[0]
    axes[1, 1].axhline(median, color="tab:red", label=f"Median = {median:g}")
    axes[1, 1].axhline(mode, color="tab:green", label=f"Mode = {mode:g}")
    axes[1, 1].set_title("Graphical location of median and mode")
    axes[1, 1].set_xlabel("Cumulative observations")
    axes[1, 1].set_ylabel("Age")
    axes[1, 1].legend()

    figure.tight_layout()
    path = output / "practical3_age_charts.png"
    figure.savefig(path, dpi=150)
    plt.close(figure)
    print(f"\nPractical 3: charts saved to {path}")
    print(f"Median = {median:g}, Mode = {mode:g}")
