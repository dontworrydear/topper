#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[50];
    float duration;
    struct Song *next;
};
struct Song *head = NULL;

void addSong() {
    struct Song *p = malloc(sizeof(struct Song));
    if (p == NULL) return;
    printf("Enter song title (one word): ");
    scanf("%49s", p->title);
    printf("Enter duration in minutes: ");
    scanf("%f", &p->duration);
    p->next = NULL;

    if (head == NULL) head = p;
    else {
        struct Song *q = head;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
}
void removeSong() {
    char name[50];
    printf("Enter title to remove: ");
    scanf("%49s", name);
    struct Song *p = head, *prev = NULL;
    while (p != NULL && strcmp(p->title, name) != 0) {
        prev = p; p = p->next;
    }
    if (p == NULL) { printf("Song not found\\n"); return; }
    if (prev == NULL) head = p->next;
    else prev->next = p->next;
    free(p);
    printf("Song removed\\n");
}
void display() {
    struct Song *p = head;
    if (p == NULL) printf("Playlist is empty\\n");
    while (p != NULL) {
        printf("%s - %.2f minutes\\n", p->title, p->duration);
        p = p->next;
    }
}
void playSong() {
    char name[50];
    printf("Enter title to play: ");
    scanf("%49s", name);
    struct Song *p = head;
    while (p != NULL && strcmp(p->title, name) != 0) p = p->next;
    if (p == NULL) printf("Song not found\\n");
    else printf("Playing: %s\\n", p->title);
}
int main() {
    int ch;
    do {
        printf("\\n1.Add 2.Remove 3.Display 4.Play 0.Exit\\n");
        scanf("%d", &ch);
        if (ch == 1) addSong();
        else if (ch == 2) removeSong();
        else if (ch == 3) display();
        else if (ch == 4) playSong();
    } while (ch != 0);
    return 0;
}
