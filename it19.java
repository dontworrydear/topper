class NumberThread extends Thread {
    int number;

    NumberThread(int number) {
        this.number = number;
    }

    public void run() {
        System.out.println("Number: " + number);
    }
}

public class NumberThreadsDemo {
    public static void main(String[] args) {
        NumberThread[] threads = new NumberThread[5];

        for (int i = 0; i < 5; i++) {
            threads[i] = new NumberThread(i + 1);
            threads[i].start();
        }

        for (int i = 0; i < 5; i++) {
            System.out.println("Thread " + (i + 1) + " alive: " + threads[i].isAlive());
        }

        try {
            for (int i = 0; i < 5; i++) {
                threads[i].join();
            }
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
            Thread.currentThread().interrupt();
        }

        System.out.println("All threads completed.");
    }
}
