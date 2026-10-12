#include <iostream> #include <string> using namespace std;  class Node { public:
int prn;
string name;
Node* next;
Node(int p, string n) {
    prn = p;
    name = n;
    next = NULL;
}
}
;
class PinnacleClub {
private:
    Node* head;

public:
    PinnacleClub() { head = NULL; }
    void addPresident() {
        int prn;
        string name;
        cout << "Enter President PRN: ";
        cin >> prn;
        cout << "Enter President Name: ";
        cin >> name;
        Node* newNode = new Node(prn, name);
        newNode->next = head;
        head = newNode;
        cout << "President added successfully.\n";
    }
    void addSecretary() {
        int prn;
        string name;
        cout << "Enter Secretary PRN: ";
        cin >> prn;
        cout << "Enter Secretary Name: ";
        cin >> name;
        Node* newNode = new Node(prn, name);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Secretary added successfully.\n";
    }
    void addMember() {
        int prn;
        string name;
        cout << "Enter Member PRN: ";
        cin >> prn;
        cout << "Enter Member Name: ";
        cin >> name;
        Node* newNode = new Node(prn, name);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            if (temp->next == NULL) {
                newNode->next = head;
                head = newNode;
            } else {
                while (temp->next->next != NULL) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        cout << "Member added successfully.\n";
    }
    void deletePresident() {
        if (head == NULL) {
            cout << "Club is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President deleted successfully.\n";
    }
    void deleteSecretary() {
        if (head == NULL) {
            cout << "Club is empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Secretary deleted successfully.\n";
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Secretary deleted successfully.\n";
    }
    void deleteMember() {
        if (head == NULL) {
            cout << "Club is empty.\n";
            return;
        }
        int prn;
        cout << "Enter PRN to delete: ";
        cin >> prn;
        if (head->prn == prn) {
            deletePresident();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->prn != prn) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Member not found.\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Member deleted successfully.\n";
    }
    int totalMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display() {
        if (head == NULL) {
            cout << "Club is empty.\n";
            return;
        }
        Node* temp = head;
        int count = 1;
        cout << "\n--- Pinnacle Club Members ---\n";
        while (temp != NULL) {
            if (count == 1)
                cout << "President";
            else if (temp->next == NULL)
                cout << "Secretary";
            else
                cout << "Member";
            cout << " -> PRN: " << temp->prn << ", Name: " << temp->name
                 << endl;
            temp = temp->next;
            count++;
        }
    }
};
int main() {
    PinnacleClub club;
    int choice;
    do {
        cout << "\n===== PINNACLE CLUB =====\n";
        cout << "1. Add President\n";
        cout << "2. Add Member\n";
        cout << "3. Add Secretary\n";
        cout << "4. Delete President\n";
        cout << "5. Delete Member\n";
        cout << "6. Delete Secretary\n";
        cout << "7. Total Members\n";
        cout << "8. Display Members\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            club.addPresident();
            break;
        case 2:
            club.addMember();
            break;
        case 3:
            club.addSecretary();
            break;
        case 4:
            club.deletePresident();
            break;
        case 5:
            club.deleteMember();
            break;
        case 6:
            club.deleteSecretary();
            break;
        case 7:
            cout << "Total members = " << club.totalMembers() << endl;
            break;
        case 8:
            club.display();
            break;
        case 9:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 9);
    return 0;
}
