# A person is selected at random then
def practical2():
    data = [
        # 15-25
        {"frequency": 17, "lower_bound": 15, "upper_bound": 25, "brand": "Acer"},
        {"frequency": 25, "lower_bound": 15, "upper_bound": 25, "brand": "Lenovo"},
        {"frequency": 17, "lower_bound": 15, "upper_bound": 25, "brand": "Dell"},
        {"frequency": 10, "lower_bound": 15, "upper_bound": 25, "brand": "hp"},
        {"frequency": 12, "lower_bound": 15, "upper_bound": 25, "brand": "Samsung"},
        # 25-35
        {"frequency": 14, "lower_bound": 25, "upper_bound": 35, "brand": "Acer"},
        {"frequency": 18, "lower_bound": 25, "upper_bound": 35, "brand": "Lenovo"},
        {"frequency": 20, "lower_bound": 25, "upper_bound": 35, "brand": "Dell"},
        {"frequency": 9,  "lower_bound": 25, "upper_bound": 35, "brand": "hp"},
        {"frequency": 11, "lower_bound": 25, "upper_bound": 35, "brand": "Samsung"},
        # 35-45
        {"frequency": 21, "lower_bound": 35, "upper_bound": 45, "brand": "Acer"},
        {"frequency": 10, "lower_bound": 35, "upper_bound": 45, "brand": "Lenovo"},
        {"frequency": 16, "lower_bound": 35, "upper_bound": 45, "brand": "Dell"},
        {"frequency": 13, "lower_bound": 35, "upper_bound": 45, "brand": "hp"},
        {"frequency": 8,  "lower_bound": 35, "upper_bound": 45, "brand": "Samsung"},
        # 45-55
        {"frequency": 13, "lower_bound": 45, "upper_bound": 55, "brand": "Acer"},
        {"frequency": 15, "lower_bound": 45, "upper_bound": 55, "brand": "Lenovo"},
        {"frequency": 12, "lower_bound": 45, "upper_bound": 55, "brand": "Dell"},
        {"frequency": 7,  "lower_bound": 45, "upper_bound": 55, "brand": "hp"},
        {"frequency": 15, "lower_bound": 45, "upper_bound": 55, "brand": "Samsung"},
        # 55-65
        {"frequency": 6,  "lower_bound": 55, "upper_bound": 65, "brand": "Acer"},
        {"frequency": 8,  "lower_bound": 55, "upper_bound": 65, "brand": "Lenovo"},
        {"frequency": 9,  "lower_bound": 55, "upper_bound": 65, "brand": "Dell"},
        {"frequency": 5,  "lower_bound": 55, "upper_bound": 65, "brand": "hp"},
        {"frequency": 4,  "lower_bound": 55, "upper_bound": 65, "brand": "Samsung"},
    ]

    total_no_of_cases = sum(element["frequency"] for element in data)

    print("\nPractical 2:")
    print("(i) what is probability that person has Lenovo laptop?")
    favourable_no_of_cases = sum(
            element["frequency"]
            for element in data
            if element["brand"] == "Lenovo"
    )
    result = favourable_no_of_cases / total_no_of_cases
    print("P(L) = " + str(result))

    print("(ii) what is probability that person is of age group 35-45 given that uses Dell laptop?")
    ii_total = sum(
            element["frequency"]
            for element in data
            if element["brand"] == "Dell"
            )
    favourable_no_of_cases = sum(
            element["frequency"]
            for element in data
            if element["brand"] == "Dell" and
             element["lower_bound"] >= 35 and element["upper_bound"] <= 45
    )
    result = favourable_no_of_cases / ii_total
    print("P((35 - 45) | D) = " + str(result))

    print("(iii) What is probability that person is of age group 25 – 35 and uses Acer laptop?")
    favourable_no_of_cases = sum(
            element["frequency"]
            for element in data
            if element["brand"] == "Acer" and
            element["lower_bound"] >= 25 and element["upper_bound"] <=35
    )
    result = favourable_no_of_cases / total_no_of_cases
    print("P((25-35) n A) = " + str(result))

    print("(iv) What is probability that person uses Samsung laptop given that of age group 55- 65?")
    iv_total = sum(
            element["frequency"]
            for element in data
            if element["lower_bound"] >= 55 and element["upper_bound"] <= 65
            )
    favourable_no_of_cases = sum(
            element["frequency"]
            for element in data
            if element["brand"] == "Samsung" and
            element["lower_bound"] >= 55 and element["upper_bound"] <= 65

    )
    result = favourable_no_of_cases / iv_total
    print("P(S | (55 - 65)) = " + str(result))

    print("(v) What is probability that person is of age group 55 – 65 given that uses hp laptop?")
    v_total = sum(
            element["frequency"]
            for element in data
            if element["brand"] == "hp"
            )
    favourable_no_of_cases = sum(
            element["frequency"]
            for element in data
            if element["brand"] == "hp" and
            element["lower_bound"] >= 55 and element["upper_bound"] <= 65
    )
    result = favourable_no_of_cases / v_total
    print("P((55 - 65) | H) = " + str(result) + "\n")



