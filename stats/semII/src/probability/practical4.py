# Practical 4:
#On rolling two dice for sum of faces of dice find

def practical4():
    data = [((a, b), a + b) for a in [1,2,3,4,5,6] for b in [1,2,3,4,5,6]]
    n = len(data)
    sumX = sum(element[1] for element in data)

    mean = sumX/n

    mu2 = sum((element[1] - mean)**2 for element in data)/n
    mu3 = sum((element[1] - mean)**3 for element in data)/n
    mu4 = sum((element[1] - mean)**4 for element in data)/n

    std = mu2**(1/2)
    skewness = mu3/(mu2**1.5)
    kurtosis = mu4/(mu2**2)

    print("(i) Mean: " + str(mean))
    print("(ii) SD: " + str(std))
    print("(iii) Skewness: " + str(skewness) )
    print("(iv) Kurtosis: " + str(kurtosis))
