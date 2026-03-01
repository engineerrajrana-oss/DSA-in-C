#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* current = &dummy;
    
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        
        struct ListNode* newNode = createNode(sum % 10);
        
        current->next = newNode;
        current = newNode;
        
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    return dummy.next;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    
    // First number: 2 -> 4 -> 3
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);
    
    // Second number: 5 -> 6 -> 4
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    printf("Result: ");
    printList(result);
    
    return 0;
}