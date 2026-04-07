#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        // If not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        // If already in recursion stack → cycle
        else if (recStack[neighbor]) {
            return true;
        }
    }

    // Remove node from recursion stack
    recStack[node] = false;
    return false;
}

// Function to check cycle in graph
bool hasCycle(int V, int** adj, int* adjSize) {
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 2;
    
    // Example: [[1,0], [0,1]] → cycle
    int edges[][2] = {{1,0}, {0,1}};
    int E = 2;

    // Create adjacency list
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int)); // worst case
    }

    // Build graph (b → a)
    for (int i = 0; i < E; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        adj[b][adjSize[b]++] = a;
    }

    // Check cycle
    if (hasCycle(V, adj, adjSize)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}