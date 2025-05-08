import csv
import matplotlib.pyplot as plt
from collections import defaultdict

data = defaultdict(list)

with open('results.csv', 'r') as file:
    content = csv.reader(file)
    next(content)

    for row in content:
        if row[1].strip()=='Random' and float(row[5]) < 1e4:
            algo = row[0]
            n = int(row[2])
            time = float(row[5])
            data[algo].append((n, time))

# Plot each algorithm's data
plt.figure(figsize=(10, 6))

for algo, values in data.items():
    values.sort()  # Sort by input size n
    x, y = zip(*values)
    plt.plot(x, y, label=algo)

plt.xlabel("Input Size (n)")
plt.ylabel("CPU Time (µs)")
plt.title("CPU Time vs Input Size per Sorting Algorithm")
plt.legend()
plt.grid(True)
plt.tight_layout()
#plt.yscale("log")
plt.show()