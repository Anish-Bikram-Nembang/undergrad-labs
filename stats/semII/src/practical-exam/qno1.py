import pandas as pd
import numpy as np
import math

def qno1():

    #to fit poission distribution and find:
    # i. F(x)
    # ii. P(X>3)
    #iii. P(X<=5)
    #iv. P(X=1)
    data = [(0,24), (1,36), (2,47), (3,68), (4,42), (5,35), (6,36)]
    df = pd.DataFrame(data, columns=["x", "observed"])

    N = df.observed.sum()
    lam = (df.x * df.observed).sum() / N

    df["P(x)"] = np.exp(-lam) * lam ** df.x / df.x.map(math.factorial)
    df["F(x)"] = df["P(x)"].cumsum()
    df["expected"] = N * df["P(x)"]

    print(f"N = {N}, lambda = {lam:.4f}\n")
    print(df.round(4).to_string(index=False))
    print(f"\nii.  P(X>3)  = {1 - df.loc[3, 'F(x)']:.4f}")
    print(f"iii. P(X<=5) = {df.loc[5, 'F(x)']:.4f}")
    print(f"iv.  P(X=1)  = {df.loc[1, 'P(x)']:.4f}\n\n")

