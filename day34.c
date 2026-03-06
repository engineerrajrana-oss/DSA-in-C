#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main()
{
    char expr[100];
    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);

    char *token = strtok(expr, " ");

    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("%d\n", pop());

    return 0;
}