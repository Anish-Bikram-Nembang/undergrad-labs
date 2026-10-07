import math

def median(data):
    s = sorted(data)
    m = len(s)
    if m % 2 == 0:
        return (s[m // 2 - 1] + s[m // 2]) / 2
    return s[m // 2]

def qno3():
    n = 16
    sectionA = [12, 10, 19, 13, 5, 14, 17, 11, 13, 18, 17, 9, 20, 14, 16, 12]
    sectionB = [17, 11, 18, 10, 15, 17, 11, 13, 15, 12, 19, 4, 13, 10, 14, 15]

    meanA = sum(sectionA) / n
    meanB = sum(sectionB) / n
    print(f"Mean of Section A: {meanA:.2f}")
    print(f"Mean of Section B: {meanB:.2f}")

    medA = median(sectionA)
    medB = median(sectionB)
    print(f"Median of Section A: {medA}")
    print(f"Median of Section B: {medB}")

    sdA = math.sqrt(sum((x - meanA) ** 2 for x in sectionA) / n)
    sdB = math.sqrt(sum((x - meanB) ** 2 for x in sectionB) / n)
    print(f"Standard Deviation of Section A: {sdA:.2f}")
    print(f"Standard Deviation of Section B: {sdB:.2f}")

    cvA = sdA / meanA * 100
    cvB = sdB / meanB * 100
    print(f"Coefficient of Variation of Section A: {cvA:.2f}%")
    print(f"Coefficient of Variation of Section B: {cvB:.2f}%")

    print("\na. Student of which section is better. Why?")
    if meanA > meanB:
        print(f"Section A is better because the mean is higher ({meanA:.2f} > {meanB:.2f}).")
    else:
        print(f"Section B is better because the mean is higher ({meanB:.2f} > {meanA:.2f}).")

    print("\nb. Student of which section is intelligent. Why?")
    if medA > medB:
        print(f"Section A is more intelligent because its median is higher ({medA} > {medB}).")
    elif medB > medA:
        print(f"Section B is more intelligent because its median is higher ({medB} > {medA}).")
    else:
        print(f"Section A and B are equally intelligent because their medians are equal ({medB} = {medA}).")


    print("\nc. Student of which section is consistent. Why?")
    if cvA < cvB:
        print(f"Section A is more consistent because its CV is lower ({cvA:.2f}% < {cvB:.2f}%).")
    else:
        print(f"Section B is more consistent because its CV is lower ({cvB:.2f}% < {cvA:.2f}%).")

