marks = []

n = int(input("Enter number of students: "))

for i in range(n):
    marks.append(float(input("Enter percentage: ")))

# Selection Sort
a = marks.copy()

for i in range(len(a)):
    min = i
    for j in range(i + 1, len(a)):
        if a[j] < a[min]:
            min = j
    a[i], a[min] = a[min], a[i]

print("Selection Sort:", a)
print("Top 5 Scores:", a[-5:])


# Quick Sort
def quick(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[0]
    left = []
    right = []

    for x in arr[1:]:
        if x <= pivot:
            left.append(x)
        else:
            right.append(x)

    return quick(left) + [pivot] + quick(right)


b = quick(marks)

print("Quick Sort:", b)
print("Top 5 Scores:", b[-5:])
