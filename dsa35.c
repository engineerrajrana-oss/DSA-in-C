

#include <stdio.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = -1, size = 0, capacity;

void enqueue(int value) {
    if (size == capacity)
        return;

    rear = (rear + 1) % capacity;
    queue[rear] = value;
    size++;
}

int dequeue() {
    if (size == 0)
        return -1;

    int value = queue[front];
    front = (front + 1) % capacity;
    size--;
    return value;
}

int main() {
    int n, m, x;

    scanf("%d", &n);
    capacity = n;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int val = dequeue();
        enqueue(val);
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", queue[(front + i) % capacity]);
    }

    return 0;
}