#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int value) {
    q->items[q->rear++] = value;
}

int dequeue(Queue *q) {
    return q->items[q->front++];
}

// BFS function
void bfs(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};
    Queue q;
    
    initQueue(&q);
    
    // Start from source
    visited[s] = 1;
    enqueue(&q, s);
    
    printf("BFS Traversal: ");
    
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        
        // Visit all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

// Main function
int main() {
    int n, s;
    int adj[MAX][MAX];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &s);
    
    bfs(n, adj, s);
    
    return 0;
}