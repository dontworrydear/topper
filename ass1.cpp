students = []

def insert_student():
    r = int(input("Enter roll no: "))
    name = input("Enter name: ")
    marks = int(input("Enter marks: "))
    students.append([r, name, marks])
    print("Student record inserted.\n")


def display():
    if len(students) == 0:
        print("There are no records")
    else:
        print("***** Student Records *****\n")
        for s in students:
            print("Roll no:", s[0])
            print("Name:", s[1])
            print("Marks:", s[2])


def search():
    Rno = int(input("Enter roll no to search: "))
    found = False

    for s in students:
        if s[0] == Rno:
            print("Record found")
            print("Roll no:", s[0])
            print("Name:", s[1])
            print("Marks:", s[2])
            found = True
            break

    if not found:
        print("Not found")


def delete():
    Rno = int(input("Enter roll no to delete: "))
    found = False

    for s in students:
        if s[0] == Rno:
            students.remove(s)
            print("Data removed successfully")
            found = True
            break

    if not found:
        print("Not found")


while True:
    print("\n1. Insert student")
    print("2. Display student")
    print("3. Search student")
    print("4. Delete student")
    print("5. Exit")

    ans = int(input("Enter which operation is to be performed: "))

    if ans == 1:
        insert_student()
    elif ans == 2:
        display()
    elif ans == 3:
        search()
    elif ans == 4:
        delete()
    elif ans == 5:
        print("Exit")
        break
    else:
        print("Invalid choice")
