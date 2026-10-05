# Following information represents student number and  result of bachelor level student under different programs.
#Find
def practical3():
    data = [
        {"program": "Science",     "students": 5500,   "pass_percentage": 45},
        {"program": "Management",  "students": 105000, "pass_percentage": 38},
        {"program": "Humanities",  "students": 21000,  "pass_percentage": 41},
        {"program": "Law",         "students": 7500,   "pass_percentage": 37},
        {"program": "Education",   "students": 38000,  "pass_percentage": 23},
        {"program": "Engineering", "students": 11000,  "pass_percentage": 76},
        {"program": "Medicine",    "students": 7000,   "pass_percentage": 77},
        {"program": "Agriculture", "students": 1500,   "pass_percentage": 83},
        {"program": "Forestry",    "students": 700,    "pass_percentage": 81},
    ]

    total_students = sum(element["students"] for element in data)
    total_pass = sum(
            (element["pass_percentage"] * element["students"]) / 100
            for element in data
    )
    total_fail = total_students - total_pass

    print("(i) what is probability that a student selected at random pass exam")
    result = total_pass / total_students
    print("P(pass) = " + str(result))

    print("(ii) what is probability that a student selected at random pass exam is Engineering student")
    favourable_no_of_cases = sum(
            (element["pass_percentage"] * element["students"]) / 100
            for element in data
            if element["program"] == "Engineering"
    )
    result = favourable_no_of_cases / total_pass
    print("P(Eng | Pass) = " + str(result))

    print("(iii) what is probability that a student selected at random fail exam is education student.")
    favourable_no_of_cases = sum(
            ((100 - element["pass_percentage"]) * element["students"]) / 100
            for element in data
            if element["program"] == "Education"
    )
    result = favourable_no_of_cases / total_fail
    print("P(Edu | Fail) = " + str(result))
