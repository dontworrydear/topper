#include <stdio.h>

int main() {
    int a[20][20], visited[20] = {0}, q[20];
    int n, start, front = 0, rear = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    q[rear++] = start;
    visited[start] = 1;
    printf("BFS: ");
    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++)
            if (a[v][i] == 1 && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
    }
    printf("\\n");
    return 0;
}
