import java.util.Scanner;

class InvalidAgeException extends Exception {
    InvalidAgeException(String message) {
        super(message);
    }
}

public class DrivingLicenseDemo {
    static void validateAge(int age) throws InvalidAgeException {
        if (age < 0) {
            throw new InvalidAgeException("Age cannot be negative.");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter your age: ");
            int age = Integer.parseInt(sc.nextLine());

            validateAge(age);

            if (age >= 18) {
                System.out.println("You are eligible for a driving license.");
            } else {
                System.out.println("You are not yet eligible for a driving license.");
            }

        } catch (NumberFormatException e) {
            System.out.println("Please enter age as a whole number.");
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic error occurred.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index is out of range.");
        } catch (InvalidAgeException e) {
            System.out.println("InvalidAgeException: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Unexpected error: " + e.getMessage());
        } finally {
            System.out.println("Operation completed.");
            sc.close();
        }
    }
}
