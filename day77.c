#include <stdlib.h>

int timeCounter;

void dfs(int u, int parent,
         int* disc, int* low, int* visited,
         int** adj, int* adjSize,
         int** result, int* resultSize) {

    visited[u] = 1;
    disc[u] = low[u] = timeCounter++;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent)
            continue;

        if (!visited[v]) {
            dfs(v, u, disc, low, visited, adj, adjSize, result, resultSize);

            // update low
            if (low[v] < low[u])
                low[u] = low[v];

            // check bridge
            if (low[v] > disc[u]) {
                result[*resultSize][0] = u;
                result[*resultSize][1] = v;
                (*resultSize)++;
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize,
                          int* returnSize, int** returnColumnSizes) {

    // allocate arrays
    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    // count degrees
    for (int i = 0; i < connectionsSize; i++) {
        adjSize[connections[i][0]]++;
        adjSize[connections[i][1]]++;
    }

    // allocate adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    // fill adjacency list
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // result
    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    for (int i = 0; i < connectionsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
    }

    int resultSize = 0;
    timeCounter = 0;

    // run DFS
    dfs(0, -1, disc, low, visited, adj, adjSize, result, &resultSize);

    *returnSize = resultSize;

    *returnColumnSizes = (int*)malloc(resultSize * sizeof(int));
    for (int i = 0; i < resultSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}