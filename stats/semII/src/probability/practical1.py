def practical1():
    data = [
            {"frequency": 3, "lower_bound": 40, "upper_bound": 50},
            {"frequency": 12, "lower_bound": 50, "upper_bound": 60},
            {"frequency": 23, "lower_bound": 60, "upper_bound": 70},
            {"frequency": 17, "lower_bound": 70, "upper_bound": 80},
            {"frequency": 8, "lower_bound": 80, "upper_bound": 90},
            {"frequency": 2, "lower_bound": 90, "upper_bound": 100},
            ]
    # an employee is selected at random then find probability that employee has weight
    #(i) Between 60 to 90 kg (ii) less than 80 kg (iii) At least 60 kg
    total_no_of_cases = sum(element["frequency"] for element in data)

    print("\nPractical 1: \ni. Between 60 to 90 kg")
    favourable_cases = sum(
            element["frequency"]
            for element in data
            if element["lower_bound"] >= 60 and element["upper_bound"] <= 90)

    result = favourable_cases/total_no_of_cases;
    print("P(60 - 90kg) = " + str(result))

    print("ii. less than 80kg")
    favourable_cases = sum(
            element["frequency"]
            for element in data
            if element["upper_bound"] <= 80)

    result = favourable_cases/total_no_of_cases
    print("P(less than 80kg) = " + str(result))

    print("iii. at least 60kg")
    favourable_cases = sum(
            element["frequency"]
            for element in data
            if element["lower_bound"] >= 60)

    result = favourable_cases/total_no_of_cases
    print("P(at least 60kg) = " + str(result)+ "\n")
