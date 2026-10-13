class BankAccount {
    static int accountCount = 0;
    String accountHolder;

    BankAccount(String accountHolder) {
        this.accountHolder = accountHolder;
        accountCount++;
    }

    void showCount() {
        System.out.println("Count from instance method: " + accountCount);
    }

    static int getAccountCount() {
        return accountCount;
    }
}

public class BankAccountDemo {
    public static void main(String[] args) {
        BankAccount a1 = new BankAccount("Rahul");
        BankAccount a2 = new BankAccount("Asha");
        BankAccount a3 = new BankAccount("Kiran");

        a1.showCount();
        System.out.println("Count from static method: " + BankAccount.getAccountCount());
    }
}
