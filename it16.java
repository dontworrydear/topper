import java.util.Scanner;

class InvalidAgeException extends Exception {
    InvalidAgeException(String message) {
        super(message);
    }
}

public class ArithmeticAgeDemo {
    static void checkAge(int age) throws InvalidAgeException {
        if (age < 0) {
            throw new InvalidAgeException("Age cannot be less than 0.");
        }
        System.out.println("Valid age: " + age);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter first integer: ");
            int a = Integer.parseInt(sc.nextLine());

            System.out.print("Enter second integer: ");
            int b = Integer.parseInt(sc.nextLine());

            System.out.println("Addition: " + (a + b));
            System.out.println("Subtraction: " + (a - b));
            System.out.println("Multiplication: " + (a * b));
            System.out.println("Division: " + (a / b));

            System.out.print("Enter age: ");
            int age = Integer.parseInt(sc.nextLine());
            checkAge(age);

        } catch (NumberFormatException e) {
            System.out.println("Please enter integers only.");
        } catch (ArithmeticException e) {
            System.out.println("Cannot divide by zero.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index is out of range.");
        } catch (InvalidAgeException e) {
            System.out.println("InvalidAgeException: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Unexpected error: " + e.getMessage());
        } finally {
            System.out.println("End of operation.");
            sc.close();
        }
    }
}
