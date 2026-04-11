#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    struct Edge edges[MAX];
    int dist[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    // Relax edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Print distances
    printf("Shortest distances from source:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d -> ", i);
        if (dist[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }

    return 0;
}
