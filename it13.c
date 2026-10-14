#include <stdio.h>

struct Edge { int u, v, w; };
int parent[20];

int find(int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}
int main() {
    struct Edge e[100], temp;
    int n, m, cost = 0, count = 0;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);
    printf("Enter each edge as: u v cost (vertices 0 to n-1)\\n");
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - 1 - i; j++)
            if (e[j].w > e[j + 1].w) {
                temp = e[j]; e[j] = e[j + 1]; e[j + 1] = temp;
            }

    printf("Selected edges:\\n");
    for (int i = 0; i < m && count < n - 1; i++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x != y) {
            parent[x] = y;
            printf("%d - %d : %d\\n", e[i].u, e[i].v, e[i].w);
            cost += e[i].w;
            count++;
        }
    }
    if (count == n - 1) printf("Total cost = %d\\n", cost);
    else printf("Graph is disconnected; MST not possible.\\n");
    return 0;
}
