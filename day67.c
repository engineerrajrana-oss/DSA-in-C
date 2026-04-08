#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Adjacency list
int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }

    // Push to stack after visiting all neighbors
    stack[++top] = node;
}

// Function to perform topological sort
void topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack (reverse order)
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n = 6; // number of nodes

    // Initialize
    for (int i = 0; i < n; i++) {
        adjSize[i] = 0;
        visited[i] = 0;
    }

    // Example DAG
    // 5 → 2, 5 → 0
    // 4 → 0, 4 → 1
    // 2 → 3
    // 3 → 1

    adj[5][adjSize[5]++] = 2;
    adj[5][adjSize[5]++] = 0;
    adj[4][adjSize[4]++] = 0;
    adj[4][adjSize[4]++] = 1;
    adj[2][adjSize[2]++] = 3;
    adj[3][adjSize[3]++] = 1;

    printf("Topological Sort: ");
    topologicalSort(n);

    return 0;
}