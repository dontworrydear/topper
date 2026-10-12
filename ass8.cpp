#include <iostream>
#include <string>
using namespace std;

#define M 5

class PizzaQueue
{
    string queue[M];
    int front, rear;

public:
    PizzaQueue()
    {
        front = -1;
        rear = -1;
    }

    // Add an order
    void addOrder()
    {
        string order;

        if ((rear + 1) % M == front)
        {
            cout << "Pizza parlor is full. Cannot accept order.\n";
            return;
        }

        cout << "Enter pizza order: ";
        cin.ignore();
        getline(cin, order);

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % M;
        }

        queue[rear] = order;

        cout << "Order placed successfully.\n";
    }

    // Serve an order
    void serveOrder()
    {
        if (front == -1)
        {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Serving order: " << queue[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % M;
        }
    }

    // Display all orders
    void displayOrders()
    {
        if (front == -1)
        {
            cout << "No orders in the queue.\n";
            return;
        }

        cout << "\nPending Orders:\n";

        int i = front;

        while (true)
        {
            cout << queue[i] << endl;

            if (i == rear)
                break;

            i = (i + 1) % M;
        }
    }
};

int main()
{
    PizzaQueue p;
    int choice;

    do
    {
        cout << "\n===== PIZZA PARLOR =====\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                p.addOrder();
                break;

            case 2:
                p.serveOrder();
                break;

            case 3:
                p.displayOrders();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
