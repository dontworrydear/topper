#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// 1. Add a new song
void addSong(string name)
{
    Node *newNode = new Node();
    newNode->song = name;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else
    {
        Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    cout << "Song added successfully.\n";
}

// 2. Delete a song
void deleteSong(string name)
{
    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    Node *temp = head;

    do
    {
        if (temp->song == name)
        {
            // Only one song in playlist
            if (temp->next == head && temp->prev == head)
            {
                head = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                // If deleting first song
                if (temp == head)
                    head = temp->next;
            }

            delete temp;
            cout << "Song deleted successfully.\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Song not found.\n";
}

// 3. Display playlist in forward direction
void displayForward()
{
    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    Node *temp = head;

    cout << "\nPlaylist (Forward):\n";

    do
    {
        cout << temp->song << endl;
        temp = temp->next;

    } while (temp != head);
}

// Display playlist in backward direction
void displayBackward()
{
    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    Node *temp = head->prev;

    cout << "\nPlaylist (Backward):\n";

    do
    {
        cout << temp->song << endl;
        temp = temp->prev;

    } while (temp != head->prev);
}

int main()
{
    int choice;
    string song;

    do
    {
        cout << "\n===== SMART MUSIC PLAYER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Backward\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
            case 1:
                cout << "Enter song name: ";
                getline(cin, song);
                addSong(song);
                break;

            case 2:
                cout << "Enter song name to delete: ";
                getline(cin, song);
                deleteSong(song);
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
