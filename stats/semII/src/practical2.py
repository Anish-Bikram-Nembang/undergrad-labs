import pandas as pd

def descriptive_stats(age):
    s = pd.Series(age)
    return pd.Series({
        "N": s.count(),
        "Mean": s.mean(),
        "Median": s.median(),
        "Mode": s.mode().tolist()[0],
        "Standard Deviation": s.std(),
        "Coefficient of Variance": s.std()/s.mean() * 100,
        "Skewness": s.skew(),
        "Kurtosis": s.kurt(),
        "First Quartile": s.quantile(0.25),
        "Second Quartile": s.quantile(0.5),
        "Third Quartile": s.quantile(0.75),
        "Interquartile Range": s.quantile(0.75) - s.quantile(0.25),
        "Max": float(s.max()),
        "Min": float(s.min()),
        "Range": float(s.max()) - float(s.min())
        })

