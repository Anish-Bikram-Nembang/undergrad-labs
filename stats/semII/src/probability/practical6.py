"""Joint and marginal distributions for the height/weight table."""


def practical6():
    heights = ["4.0-4.6", "4.6-5.2", "5.2-5.8", "5.8-6.4"]
    weights = ["45-55", "55-65", "65-75", "75-85"]
    frequencies = [
        [2, 4, 1, 0],
        [5, 20, 9, 1],
        [3, 32, 21, 6],
        [1, 13, 24, 9],
    ]
    total = sum(map(sum, frequencies))
    row_totals = [sum(row) for row in frequencies]
    column_totals = [
        sum(frequencies[row][column] for row in range(len(heights)))
        for column in range(len(weights))
    ]

    print("\nPractical 6:")
    print("Joint probability distribution P(height, weight):")
    print("height/weight  " + "  ".join(f"{weight:>8}" for weight in weights))
    for height, row in zip(heights, frequencies):
        values = "  ".join(f"{frequency / total:8.4f}" for frequency in row)
        print(f"{height:>12}  {values}")

    print("\nMarginal distribution of height:")
    for height, frequency in zip(heights, row_totals):
        print(f"P({height}) = {frequency / total:.4f}")

    print("\nMarginal distribution of weight:")
    for weight, frequency in zip(weights, column_totals):
        print(f"P({weight}) = {frequency / total:.4f}")

    print("\nMarginal distribution functions:")
    cumulative = 0
    for height, frequency in zip(heights, row_totals):
        cumulative += frequency
        print(f"F(height <= {height}) = {cumulative / total:.4f}")
    cumulative = 0
    for weight, frequency in zip(weights, column_totals):
        cumulative += frequency
        print(f"F(weight <= {weight}) = {cumulative / total:.4f}")
