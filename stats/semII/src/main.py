import pandas as pd
import numpy as np

df= pd.read_spss("~/Downloads/data1.sav")

sample = df.sample(n=500, random_state=67)
age = sample['Age'].to_numpy(dtype=float)

MAX = float(age.max())
MIN = float(age.min())

noOfClasses = 1 + 3.322*np.log10(500)
classInterval = np.ceil((MAX-MIN)/noOfClasses)

bins = np.arange(MIN, MAX + classInterval + 1, classInterval)
cut = pd.cut(
        age,
        bins=bins,
        right=False
        )
frequency = pd.Series(cut).value_counts().sort_index()

total = len(sample)
valid = frequency.sum()

table = pd.DataFrame({
    "Frequency": frequency,
    "Percent": frequency/total * 100,
    "Valid Percent": frequency/valid * 100,
    "Cumulative Percent": (frequency/valid * 100).cumsum()
    })
total_row = pd.DataFrame({
    "Frequency": [frequency.sum()],
    "Percent": [frequency.sum()/total * 100],
    "Valid Percent": [100.0],
    "Cumulative Percent": [np.nan]
    }, index=["Total"])

table_with_total = pd.concat([table, total_row])
print(table_with_total.round(1))

s = pd.Series(age)
s.describe()
n = s.count()
mean = s.mean()
median = s.median()
modes = s.mode()
std = s.std()
cv = std/mean * 100
skew = s.skew()
kurt = s.kurt()
q1, q2, q3 = s.quantile([0.25, 0.5, 0.75])
iqr = q3-q1
mn,mx = s.min(), s.max()
rng = mx - mn

stats = pd.Series({
    "N": n , "Mean" : mean,"Median": median, "Mode": modes[0], "Standard Deviation": std, "Coefficient of Variance": cv,
    "Skewness": skew, "Kurtosis": kurt, "First Quartile": q1, "Second Quartile": q2, "Third Quartile": q3, "Interquartile Range": iqr, "Max": mx, "Min": mn, "Range": rng
    })
print(stats.round(3))
