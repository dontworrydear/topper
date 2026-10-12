ASSIGNMENT NO. 5

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *next;
};

Node *current = NULL;

// Add a player
void addPlayer(string name)
{
    Node *newNode = new Node;
    newNode->name = name;

    if (current == NULL)
    {
        current = newNode;
        newNode->next = current;
    }
    else
    {
        Node *temp = current;

        while (temp->next != current)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = current;
    }

    cout << "Player added successfully!\n";
}

// Remove a player
void removePlayer(string name)
{
    if (current == NULL)
    {
        cout << "No players in the game.\n";
        return;
    }

    Node *temp = current;
    Node *prev = NULL;

    do
    {
        if (temp->name == name)
            break;

        prev = temp;
        temp = temp->next;

    } while (temp != current);

    if (temp->name != name)
    {
        cout << "Player not found.\n";
        return;
    }

    // Only one player
    if (temp->next == temp)
    {
        delete temp;
        current = NULL;
    }
    else
    {
        // Find last node
        Node *last = current;

        while (last->next != current)
        {
            last = last->next;
        }

        if (temp == current)
        {
            current = current->next;
            last->next = current;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;
    }

    cout << "Player removed successfully!\n";
}

// Move to next player
void nextPlayer()
{
    if (current == NULL)
    {
        cout << "No players in the game.\n";
        return;
    }

    current = current->next;

    cout << "Turn moved to: " << current->name << endl;
}

// Display current player
void displayCurrent()
{
    if (current == NULL)
    {
        cout << "No players in the game.\n";
    }
    else
    {
        cout << "Current turn: " << current->name << endl;
    }
}

int main()
{
    int choice;
    string name;

    do
    {
        cout << "\n===== PLAYER TURN MANAGEMENT =====\n";
        cout << "1. Add Player\n";
        cout << "2. Remove Player\n";
        cout << "3. Move to Next Player\n";
        cout << "4. Display Current Turn\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter player name: ";
                cin >> name;
                addPlayer(name);
                break;

            case 2:
                cout << "Enter player name: ";
                cin >> name;
                removePlayer(name);
                break;

            case 3:
                nextPlayer();
                break;

            case 4:
                displayCurrent();
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
