import numpy as np
import pandas as pd

def make_bins(age):
    n = len(age)
    mx, mn = float(age.max()), float(age.min())
    no_of_classes = 1 + 3.322 * np.log10(n)
    class_interval = np.ceil((mx - mn) / no_of_classes)
    return np.arange(mn, mx + class_interval + 1, class_interval)

def frequency_table(age):
    n = len(age)
    bins = make_bins(age)

    cut = pd.cut(age, bins=bins, right=False)
    frequency = pd.Series(cut).value_counts().sort_index()
    valid = frequency.sum()

    table = pd.DataFrame({
        "Frequency": frequency,
        "Percent": frequency/n * 100,
        "Valid Percent": frequency/valid * 100,
        "Cumulative Percent": (frequency/valid * 100).cumsum(),
        })

    total_row = pd.DataFrame({
        "Frequency": [valid],
        "Percent": [valid/n * 100],
        "Valid Percent": [100.0],
        "Cumulative Percent": [np.nan]
        }, index=["Total"])

    return pd.concat([table, total_row])
