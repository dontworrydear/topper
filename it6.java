class Book {
    static int bookCount = 0;
    String title;

    Book(String title) {
        this.title = title;
        bookCount++;
    }

    void showCount() {
        System.out.println("Count from instance method: " + bookCount);
    }

    static int getBookCount() {
        return bookCount;
    }
}

public class BookCountDemo {
    public static void main(String[] args) {
        Book b1 = new Book("Java");
        Book b2 = new Book("Python");
        Book b3 = new Book("C Programming");

        b1.showCount();
        System.out.println("Count from static method: " + Book.getBookCount());
    }
}
