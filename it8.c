#include <stdio.h>
#define MAX 5

char q[MAX];
int front = -1, rear = -1;

void insert() {
    char c;
    if ((rear + 1) % MAX == front) {
        printf("Overflow\\n"); return;
    }
    printf("Enter character: ");
    scanf(" %c", &c);
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    q[rear] = c;
}
void deleteItem() {
    if (front == -1) { printf("Underflow\\n"); return; }
    printf("Deleted: %c\\n", q[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}
void display() {
    if (front == -1) { printf("Queue empty\\n"); return; }
    int i = front;
    while (1) {
        printf("%c ", q[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\\n");
}
int main() {
    int ch;
    do {
        printf("\\n1.Insert 2.Delete 3.Display 0.Exit\\n");
        scanf("%d", &ch);
        if (ch == 1) insert();
        else if (ch == 2) deleteItem();
        else if (ch == 3) display();
    } while (ch != 0);
    return 0;
}
