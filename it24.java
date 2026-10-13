import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ProductFileAverage {
    public static void main(String[] args) {
        double totalPrice = 0;
        int count = 0;

        try (BufferedReader br = new BufferedReader(new FileReader("product_info.txt"))) {
            String line;

            while ((line = br.readLine()) != null) {
                String[] parts = line.trim().split("\\\\s+");
                if (parts.length >= 2) {
                    totalPrice += Double.parseDouble(parts[parts.length - 1]);
                    count++;
                }
            }

            if (count > 0) {
                System.out.println("Average product price: " + (totalPrice / count));
            } else {
                System.out.println("No product records found.");
            }
        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("A product price in the file is not numeric.");
        }
    }
}
