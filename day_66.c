class Solution {
public:

    bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &recStack) {
        visited[node] = 1;
        recStack[node] = 1;

        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfs(neigh, adj, visited, recStack))
                    return true;
            }
            else if (recStack[neigh]) {
                return true; // cycle found
            }
        }

        recStack[node] = 0; // remove from recursion stack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        
        // Step 1: create adjacency list
        vector<int> adj[V];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]); // directed
        }

        vector<int> visited(V, 0), recStack(V, 0);

        // Step 2: check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};
