from data import load_sample, get_age
from statistics.practical1 import frequency_table
from statistics.practical2 import descriptive_stats
from probability.practical1 import practical1

def main():
    sample = load_sample()
    age = get_age(sample)

    print("Practical 1: Frequency Distribution")
    print(frequency_table(age).round(1))

    print("\nPractical 2: Descriptive Statistics")
    print(descriptive_stats(age).round(3))

    practical1()


if __name__ == "__main__":
    main()
