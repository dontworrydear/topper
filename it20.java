class EvenThread extends Thread {
    int number;

    EvenThread(int number) {
        this.number = number;
    }

    public void run() {
        System.out.println("Even number: " + number);
    }
}

public class EvenThreadsDemo {
    public static void main(String[] args) {
        EvenThread[] threads = new EvenThread[5];

        for (int i = 0; i < 5; i++) {
            threads[i] = new EvenThread((i + 1) * 2);
            threads[i].start();
        }

        for (int i = 0; i < 5; i++) {
            System.out.println("Thread for " + ((i + 1) * 2) +
                               " alive: " + threads[i].isAlive());
        }

        try {
            for (int i = 0; i < 5; i++) {
                threads[i].join();
            }
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
            Thread.currentThread().interrupt();
        }

        System.out.println("All threads finished.");
    }
}
