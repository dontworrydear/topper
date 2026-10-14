#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node *insert(struct Node *r, int x) {
    if (r == NULL) {
        r = malloc(sizeof(struct Node));
        r->data = x; r->left = r->right = NULL;
    } else if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}
struct Node *minimum(struct Node *r) {
    while (r && r->left) r = r->left;
    return r;
}
struct Node *deleteNode(struct Node *r, int x) {
    if (r == NULL) return NULL;
    if (x < r->data) r->left = deleteNode(r->left, x);
    else if (x > r->data) r->right = deleteNode(r->right, x);
    else {
        if (r->left == NULL) {
            struct Node *t = r->right; free(r); return t;
        }
        if (r->right == NULL) {
            struct Node *t = r->left; free(r); return t;
        }
        struct Node *t = minimum(r->right);
        r->data = t->data;
        r->right = deleteNode(r->right, t->data);
    }
    return r;
}
int search(struct Node *r, int x) {
    if (r == NULL) return 0;
    if (r->data == x) return 1;
    if (x < r->data) return search(r->left, x);
    return search(r->right, x);
}
void inorder(struct Node *r) {
    if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); }
}
int main() {
    struct Node *root = NULL;
    int ch, x;
    do {
        printf("\\n1.Insert 2.Delete 3.Search 4.Display 0.Exit\\n");
        scanf("%d", &ch);
        if (ch >= 1 && ch <= 3) {
            printf("Enter value: "); scanf("%d", &x);
        }
        if (ch == 1) root = insert(root, x);
        else if (ch == 2) root = deleteNode(root, x);
        else if (ch == 3) printf(search(root, x) ? "Found\\n" : "Not found\\n");
        else if (ch == 4) { inorder(root); printf("\\n"); }
    } while (ch != 0);
    return 0;
}
