#include <stdio.h>

int linear(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

int recursiveLinear(int a[], int n, int key, int i) {
    if (i == n) return -1;
    if (a[i] == key) return i;
    return recursiveLinear(a, n, key, i + 1);
}

int main() {
    int a[50], n, key;
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);

    int p = linear(a, n, key);
    if (p == -1) printf("Not found\\n");
    else printf("Non-recursive position: %d\\n", p + 1);

    p = recursiveLinear(a, n, key, 0);
    if (p == -1) printf("Not found\\n");
    else printf("Recursive position: %d\\n", p + 1);
    return 0;
}
