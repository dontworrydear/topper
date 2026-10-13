class Employee {
    static int employeeCount = 0;
    String name;

    Employee(String name) {
        this.name = name;
        employeeCount++;
    }

    void showCount() {
        System.out.println("Count from instance method: " + employeeCount);
    }

    static int getEmployeeCount() {
        return employeeCount;
    }
}

public class EmployeeDemo {
    public static void main(String[] args) {
        Employee e1 = new Employee("Amit");
        Employee e2 = new Employee("Priya");
        Employee e3 = new Employee("Neha");

        e1.showCount();
        System.out.println("Count from static method: " + Employee.getEmployeeCount());
    }
}
