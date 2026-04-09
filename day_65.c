#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function to detect cycle
int dfs(int adj[MAX][MAX], int n, int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            if (!visited[i]) {
                if (dfs(adj, n, i, node))
                    return 1;
            }
            else if (i != parent) {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int hasCycle = 0;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, n, i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
