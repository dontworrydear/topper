import java.util.Scanner;

class InvalidMarksException extends Exception {
    InvalidMarksException(String message) {
        super(message);
    }
}

public class MarksExceptionDemo {
    static void validateMarks(int marks) throws InvalidMarksException {
        if (marks < 0 || marks > 100) {
            throw new InvalidMarksException("Marks must be between 0 and 100.");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter marks for subject 1: ");
            int m1 = Integer.parseInt(sc.nextLine());
            validateMarks(m1);

            System.out.print("Enter marks for subject 2: ");
            int m2 = Integer.parseInt(sc.nextLine());
            validateMarks(m2);

            System.out.print("Enter marks for subject 3: ");
            int m3 = Integer.parseInt(sc.nextLine());
            validateMarks(m3);

            double percentage = (m1 + m2 + m3) / 3.0;
            System.out.println("Percentage: " + percentage + "%");

        } catch (NumberFormatException e) {
            System.out.println("Please enter numeric marks.");
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic error while calculating result.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index is out of range.");
        } catch (InvalidMarksException e) {
            System.out.println("InvalidMarksException: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Unexpected error: " + e.getMessage());
        } finally {
            System.out.println("Result processing completed");
            sc.close();
        }
    }
}
