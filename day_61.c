#include <stdio.h>

#define MAX 100

int main() {
    int n, m, isDirected;
    int adj[MAX][MAX] = {0}; // Initialize matrix with 0

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    printf("Enter %d pairs of edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Add edge from u to v
        adj[u][v] = 1;
        
        // If undirected, add edge from v to u as well
        if (!isDirected) {
            adj[v][u] = 1;
        }
    }

    // Print the Adjacency Matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
