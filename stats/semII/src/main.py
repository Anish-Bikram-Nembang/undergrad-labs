from data import load_sample, get_age
from statistics.practical1 import frequency_table
from statistics.practical2 import descriptive_stats
from statistics.practical3 import practical3 as stats_practical3
from statistics.practical4 import practical4 as stats_practical4
from statistics.practical5 import practical5 as stats_practical5
from statistics.practical6 import practical6 as stats_practical6
from statistics.practical7 import practical7 as stats_practical7
from statistics.practical8 import practical8 as stats_practical8
from statistics.practical9 import practical9 as stats_practical9
from probability.practical1 import practical1
from probability.practical2 import practical2
from probability.practical3 import practical3
from probability.practical4 import practical4
from probability.practical5 import practical5
from probability.practical6 import practical6
from probability.practical7 import practical7
from probability.practical8 import practical8
from probability.practical9 import practical9
from probability.practical10 import practical10

def main():
    sample = load_sample()
    age = get_age(sample)

    print("Practical 1: Frequency Distribution")
    print(frequency_table(age).round(1))

    print("\nPractical 2: Descriptive Statistics")
    print(descriptive_stats(age).round(3))

    stats_practical3(sample)
    stats_practical4(sample)
    stats_practical5(sample)
    stats_practical6(sample)
    stats_practical7(sample)
    stats_practical8(sample)
    stats_practical9(sample)

    practical1()
    practical2()
    practical3()
    practical4()
    practical5()
    practical6()
    practical7()
    practical8()
    practical9()
    practical10()


if __name__ == "__main__":
    main()
