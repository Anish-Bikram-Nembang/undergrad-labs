from data import load_sample, get_age
from practical1 import frequency_table
from practical2 import descriptive_stats

def main():
    sample = load_sample()
    age = get_age(sample)

    print("Practical 1: Frequency Distribution")
    print(frequency_table(age).round(1))

    print("\nPractical 2: Descriptive Statistics")
    print(descriptive_stats(age).round(3))


if __name__ == "__main__":
    main()
