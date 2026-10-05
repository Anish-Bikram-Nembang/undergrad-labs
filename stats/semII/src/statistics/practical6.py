from collections import defaultdict

from data import load_sample


def practical6(sample=None, seed=67):
    sample = load_sample() if sample is None else sample
    respondent_type = sample["typeofrespondent"].dropna().unique()[0]
    mask = sample["typeofrespondent"] == respondent_type
    selected = sample[mask].sample(n=min(50, mask.sum()), random_state=seed)
    stems = defaultdict(list)
    for value in sorted(selected["Age"].dropna().astype(int)):
        stems[value // 10].append(value % 10)
    print(f"\nPractical 6: stem-and-leaf plot for {respondent_type!r}")
    for stem in sorted(stems):
        print(f"{stem} | {' '.join(map(str, stems[stem]))}")
    print("Key: 3 | 4 means age 34")