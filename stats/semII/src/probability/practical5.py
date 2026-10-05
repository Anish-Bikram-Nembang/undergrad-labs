#Practical 5
#Following data represents marks obtained by student in a chapter test.
#Form probability distribution and find
def practical5():
    data = [(1,2), (2,3), (3,5), (4,11), (5,15), (6,13), (7,10), (8,7), (9,3), (10,2)]
    sumX = sum(x * f for x, f in data)
    n = sum(f for x, f in data)

    mean = sumX / n
    max_f = max(f for x, f in data)
    mode = [x for x, f in data if f == max_f][0]

    cum = 0
    for x, f in data:
        cum += f
        if cum >= n / 2:
            median = x
            break

    moments_about_origin = [sum(f * x**r for x, f in data) / n for r in range(1, 5)]
    moments_about_mean = [sum(f * (x - mean)**r for x, f in data) / n for r in range(1, 5)]

    mu2, mu3, mu4 = moments_about_mean[1:4]
    sd = mu2 ** 0.5
    cv = sd / mean * 100
    beta1 = mu3**2 / mu2**3
    gamma1 = mu3 / mu2**1.5
    beta2 = mu4 / mu2**2

    print("Probability distribution:")
    print("  x    f     p(x)")
    for x, f in data:
        print(f"{x:3d} {f:4d}  {f / n:.4f}")
    print(f"Total N = {n}\n")

    print("(i) moments about origin")
    for r, m in enumerate(moments_about_origin, start=1):
        print(f"  mu{r}' = {m:.4f}")

    print("(ii) moments about mean")
    for r, m in enumerate(moments_about_mean, start=1):
        print(f"  mu{r} = {m:.4f}")

    print("(iii) measure of central tendency")
    print(f"  Mean   = {mean:.4f}")
    print(f"  Median = {median}")
    print(f"  Mode   = {mode}")

    print("(iv) measure of dispersion")
    print(f"  Variance = {mu2:.4f}")
    print(f"  SD       = {sd:.4f}")
    print(f"  CV       = {cv:.2f}%")

    print("(v) measure of skewness")
    print(f"  beta1  = {beta1:.4f}")
    print(f"  gamma1 = {gamma1:.4f}")

    print("(vi) measure of kurtosis of marks.")
    print(f"  beta2 = {beta2:.4f}")
    print(f"  gamma2 (excess) = {beta2 - 3:.4f}")
