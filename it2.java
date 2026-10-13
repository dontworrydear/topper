class Book {
    String title;
    String author;
    double price;
    int bookId;

    Book() {
        this.title = "Unknown";
        this.author = "Unknown";
        this.price = 0.0;
        this.bookId = 0;
    }

    Book(String title, String author, double price, int bookId) {
        this.title = title;
        this.author = author;
        this.price = price;
        this.bookId = bookId;
    }

    void displayDetails() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
        System.out.println("Book ID: " + bookId);
        System.out.println();
    }

    void updatePrice(double price) {
        this.price = price;
    }
}

public class BookDemo {
    public static void main(String[] args) {
        Book b1 = new Book();
        Book b2 = new Book("Java Basics", "R. Sharma", 450.0, 101);

        System.out.println("Book 1:");
        b1.displayDetails();

        System.out.println("Book 2 before price update:");
        b2.displayDetails();

        b2.updatePrice(500.0);
        System.out.println("Book 2 after price update:");
        b2.displayDetails();
    }
}
