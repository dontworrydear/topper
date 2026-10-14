#include <stdio.h>

int binary(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int recursiveBinary(int a[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key)
        return recursiveBinary(a, mid + 1, high, key);
    return recursiveBinary(a, low, mid - 1, key);
}

int main() {
    int a[50], n, key;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);

    int p = binary(a, n, key);
    printf("Non-recursive position: %d\\n", p == -1 ? -1 : p + 1);
    p = recursiveBinary(a, 0, n - 1, key);
    printf("Recursive position: %d\\n", p == -1 ? -1 : p + 1);
    return 0;
}
