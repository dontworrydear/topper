#include <iostream>
using namespace std;

class myQueue {

    // Array to store queue elements.
    int *arr;

    // Maximum number of elements the queue can hold.
    int capacity;

    // Current number of elements in the queue.
    int size;

  public:
    myQueue(int c) {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }

    // Adds an element x at the rear of the queue.
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        arr[size] = x;
        size++;
    }

    // Removes the front element of the queue.
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    // Returns the front element of the queue.
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }
    // Return the last element of queue
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[size - 1];
    }
};

int main() {
    myQueue q(3);

    // Insert elements into the queue.
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Get the front element.
    cout << q.getFront() << endl;

    // Remove the front element.
    q.dequeue();

    // Get the new front element.
    cout << q.getFront() << endl;

    // Get the rear element.
    cout << q.getRear() << endl;

    // Try to insert another element.
    q.enqueue(40);

    return 0;
}
