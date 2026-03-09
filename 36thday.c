#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x) {
    pq[size++] = x;
}

int getMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int deleteMin() {
    if (size == 0) return -1;

    int minIndex = getMinIndex();
    int value = pq[minIndex];

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
    return value;
}

int peek() {
    if (size == 0) return -1;

    int minIndex = getMinIndex();
    return pq[minIndex];
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } 
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } 
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}