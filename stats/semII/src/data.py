import pandas as pd

def load_sample(path="~/Downloads/data1.sav", n=500, seed=67):
    return pd.read_spss(path).sample(n=n, random_state=seed)

def get_age(sample):
    return sample['Age'].to_numpy(dtype=float)

