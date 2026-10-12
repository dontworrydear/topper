book = []

def insert():
    n = int(input("Enter the number of Books: "))
    for i in range(n):
        b = int(input("Enter the Book-id: "))
        book.append(b)

book.sort()
insert()

def linearsearch():
    key1 = int(input("Enter the book-id to search: "))

    for i in range(len(book)):
        if book[i] == key1:
            print("------Book record found-----")
            print("Location of book at index:", i)
            break
    else:
        print("-------No record found-------")


def binarysearch():
    low = 0
    high = len(book) - 1
    mid = (low + high) // 2

    key2 = int(input("Enter the book-id to search: "))

    while low <= high:
        if key2 == book[mid]:
            print("------Book record found-----")
            print("Location of book at index:", mid)
            break

        elif key2 > book[mid]:
            low = mid + 1
            mid = (low + high) // 2

        elif key2 < book[mid]:
            high = mid - 1
            mid = (low + high) // 2
    else:
        print("-------No record found-------")


while True:
    print("1. Linear Search")
    print("2. Binary Search")

    choice = int(input("Enter the operation to perform: "))

    if choice == 1:
        linearsearch()
        break

    elif choice == 2:
        binarysearch()
        break

    else:
        print("Invalid choice")
