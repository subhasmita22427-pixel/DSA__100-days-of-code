#include <stdio.h>

#define MAX 100

int visited[MAX];
int stack[MAX], top = -1;

// push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int adj[MAX][MAX], int n, int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(adj, n, i);
        }
    }

    push(node); // push after visiting neighbors
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

    // initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // call DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, n, i);
        }
    }

    // print topological order
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
