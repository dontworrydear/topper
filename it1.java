class Student {
    String name;
    int age;
    int rollNo;
    double marks;

    Student() {
        this.name = "Not set";
        this.age = 0;
        this.rollNo = 0;
        this.marks = 0.0;
    }

    Student(String name, int age, int rollNo, double marks) {
        this.name = name;
        this.age = age;
        this.rollNo = rollNo;
        this.marks = marks;
    }

    void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Roll No: " + rollNo);
        System.out.println("Marks: " + marks);
        System.out.println();
    }

    void updateMarks(double marks) {
        this.marks = marks;
    }
}

public class StudentDemo {
    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new Student("Asha", 19, 12, 82.5);

        System.out.println("Student 1:");
        s1.displayDetails();

        System.out.println("Student 2 before updating marks:");
        s2.displayDetails();

        s2.updateMarks(90.0);
        System.out.println("Student 2 after updating marks:");
        s2.displayDetails();
    }
}
