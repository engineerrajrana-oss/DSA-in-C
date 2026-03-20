#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int degree[MAX];

int main() {
    int n;
    scanf("%d", &n);

    // Special case: only one node
    if (n == 1) {
        printf("1\n");
        return 0;
    }

    // Initialize degrees
    for (int i = 1; i <= n; i++) {
        degree[i] = 0;
    }

    // Read edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }

    int leafCount = 0;

    for (int i = 2; i <= n; i++) {
        if (degree[i] == 1) {
            leafCount++;
        }
    }

    printf("%d\n", leafCount);

    return 0;
}