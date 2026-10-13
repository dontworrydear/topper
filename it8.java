class Person {
    String name;
    int age;
    String address;

    Person(String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }

    void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
    }
}

class Student extends Person {
    int rollNo;
    String course;

    Student(String name, int age, String address, int rollNo, String course) {
        super(name, age, address);
        this.rollNo = rollNo;
        this.course = course;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Roll No: " + rollNo);
        System.out.println("Course: " + course);
    }
}

public class PersonStudentDemo {
    public static void main(String[] args) {
        Person p = new Person("Rahul", 40, "Pune");
        Student s = new Student("Asha", 19, "Mumbai", 15, "Computer Engineering");

        System.out.println("Person details:");
        p.displayDetails();
        System.out.println("\\nStudent details:");
        s.displayDetails();
    }
}
