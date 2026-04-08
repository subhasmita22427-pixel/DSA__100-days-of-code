#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int n;       // number of vertices
    Node** adj;  // array of adjacency lists
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->adj = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++)
        graph->adj[i] = NULL;
    return graph;
}

// Function to add an edge (undirected graph)
void addEdge(Graph* graph, int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = graph->adj[u];
    graph->adj[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = graph->adj[v];
    graph->adj[v] = nodeU;
}

// DFS recursive function
void DFSUtil(Graph* graph, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = graph->adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFSUtil(graph, temp->vertex, visited);
        temp = temp->next;
    }
}

// DFS function
void DFS(Graph* graph, int start) {
    int* visited = (int*)calloc(graph->n, sizeof(int));
    DFSUtil(graph, start, visited);
    free(visited);
}

int main() {
    int n, m, u, v, s;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    DFS(graph, s);
    printf("\n");

    // Free memory
    for (int i = 0; i < n; i++) {
        Node* temp = graph->adj[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adj);
    free(graph);

    return 0;
}
