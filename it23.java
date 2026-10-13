import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class EmployeeFileAverage {
    public static void main(String[] args) {
        double totalSalary = 0;
        int count = 0;

        try (BufferedReader br = new BufferedReader(new FileReader("employee_info.txt"))) {
            String line;

            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\\\s+");
                if (parts.length >= 2) {
                    totalSalary += Double.parseDouble(parts[parts.length - 1]);
                    count++;
                }
            }

            if (count > 0) {
                System.out.println("Average salary: " + (totalSalary / count));
            } else {
                System.out.println("No employee records found.");
            }
        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("A salary value in the file is not numeric.");
        }
    }
}
