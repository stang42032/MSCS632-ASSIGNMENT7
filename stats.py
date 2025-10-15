class StatisticsCalculator:
    def __init__(self, numbers):
        self.numbers = sorted(numbers)

    def mean(self):
        return sum(self.numbers) / len(self.numbers)

    def median(self):
        n = len(self.numbers)
        mid = n // 2
        if n % 2 == 0:
            return (self.numbers[mid - 1] + self.numbers[mid]) / 2
        return self.numbers[mid]

    def mode(self):
        frequency = {}
        for num in self.numbers:
            frequency[num] = frequency.get(num, 0) + 1
        max_freq = max(frequency.values())
        return [num for num, freq in frequency.items() if freq == max_freq]

if __name__ == "__main__":
    nums = list(map(int, input("Enter integers separated by spaces: ").split()))
    stats = StatisticsCalculator(nums)

    print(f"Mean: {stats.mean():.2f}")
    print(f"Median: {stats.median():.2f}")
    print("Mode(s):", *stats.mode())
