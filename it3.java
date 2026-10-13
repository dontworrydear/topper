class Product {
    String productName;
    int productId;
    int quantity;
    double price;

    Product() {
        this.productName = "Unknown";
        this.productId = 0;
        this.quantity = 0;
        this.price = 0.0;
    }

    Product(String productName, int productId, int quantity, double price) {
        this.productName = productName;
        this.productId = productId;
        this.quantity = quantity;
        this.price = price;
    }

    void displayDetails() {
        System.out.println("Product: " + productName);
        System.out.println("Product ID: " + productId);
        System.out.println("Quantity: " + quantity);
        System.out.println("Price: " + price);
        System.out.println();
    }

    void updateQuantity(int quantity) {
        this.quantity = quantity;
    }
}

public class ProductDemo {
    public static void main(String[] args) {
        Product p1 = new Product();
        Product p2 = new Product("Notebook", 202, 10, 45.0);

        System.out.println("Product 1:");
        p1.displayDetails();

        System.out.println("Product 2 before quantity update:");
        p2.displayDetails();

        p2.updateQuantity(25);
        System.out.println("Product 2 after quantity update:");
        p2.displayDetails();
    }
}
