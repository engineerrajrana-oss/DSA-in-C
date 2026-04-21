#include <stdio.h>

#define MAX 100
#define INF 1000000000

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int source;
    scanf("%d", &source);

    // initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1;

        // find minimum distance node
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = 1;

        // relax edges
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // output
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}