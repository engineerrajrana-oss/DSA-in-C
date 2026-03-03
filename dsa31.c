#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);

        if(operation == 1) {  // PUSH
            int value;
            scanf("%d", &value);
            
            if(top == SIZE - 1) {
                // Stack Overflow (not required but safe)
                continue;
            }
            
            top++;
            stack[top] = value;
        }
        else if(operation == 2) {  // POP
            if(top == -1) {
                printf("Stack Underflow\n");
            }
            else {
                printf("%d\n", stack[top]);
                top--;
            }
        }
        else if(operation == 3) {  // DISPLAY
            if(top == -1) {
                // If empty, print nothing (as per problem)
                printf("\n");
            }
            else {
                for(int j = top; j >= 0; j--) {
                    printf("%d ", stack[j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}