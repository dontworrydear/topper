#include <stdio.h>

int a[20][20], visited[20], n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (a[v][i] == 1 && !visited[i]) dfs(i);
}

int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("DFS: ");
    dfs(start);
    printf("\\n");
    return 0;
}
