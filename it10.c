#include <stdio.h>

int main() {
    int a[20][20], n;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 or 1):\\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Adjacency Matrix:\\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
        printf("\\n");
    }
    return 0;
}
