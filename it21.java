class AlphabetThread extends Thread {
    char letter;

    AlphabetThread(char letter) {
        this.letter = letter;
    }

    public void run() {
        System.out.println("Letter: " + letter);
    }
}

public class AlphabetThreadsDemo {
    public static void main(String[] args) {
        AlphabetThread[] threads = new AlphabetThread[5];

        for (int i = 0; i < 5; i++) {
            threads[i] = new AlphabetThread((char) ('A' + i));
            threads[i].start();
        }

        for (int i = 0; i < 5; i++) {
            System.out.println("Thread " + threads[i].letter +
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

        System.out.println("All threads completed.");
    }
}
