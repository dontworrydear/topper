abstract class Payment {
    abstract void makePayment();
}

class UPIPayment extends Payment {
    void makePayment() {
        System.out.println("Payment made using UPI");
    }
}

class CardPayment extends Payment {
    void makePayment() {
        System.out.println("Payment made using Card");
    }
}

public class PaymentDemo {
    public static void main(String[] args) {
        Payment[] payments = { new UPIPayment(), new CardPayment() };

        for (Payment payment : payments) {
            payment.makePayment();
        }
    }
}
