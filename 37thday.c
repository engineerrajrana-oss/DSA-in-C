#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == (rear + 1) % MAX);
}

void push_front(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = value;
}

void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = value;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

int getFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[front];
}

int getBack() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[rear];
}

int size() {
    if (isEmpty()) return 0;
    if (rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    display();

    return 0;
}