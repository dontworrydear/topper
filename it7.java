class Employee {
    int empId;
    String name;
    double salary;

    Employee(int empId, String name, double salary) {
        this.empId = empId;
        this.name = name;
        this.salary = salary;
    }

    void displayDetails() {
        System.out.println("Employee ID: " + empId);
        System.out.println("Name: " + name);
        System.out.println("Salary: " + salary);
    }
}

class Manager extends Employee {
    String department;

    Manager(int empId, String name, double salary, String department) {
        super(empId, name, salary);
        this.department = department;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Department: " + department);
    }
}

public class ManagerDemo {
    public static void main(String[] args) {
        Employee e = new Employee(1, "Amit", 35000);
        Manager m = new Manager(2, "Priya", 60000, "IT");

        System.out.println("Employee details:");
        e.displayDetails();
        System.out.println("\\nManager details:");
        m.displayDetails();
    }
}
