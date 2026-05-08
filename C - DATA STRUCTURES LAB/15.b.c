// Write a program to implement Stack using Array and Linked List
// (Stack Using Linked List)
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->next = top;
    top = new;
}
void pop() {
    if(top == NULL)
        printf("Stack Underflow\n");
    else {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}
void display() {
    struct node *temp = top;
    if(temp == NULL)
        printf("Stack is empty\n");
    else {
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int choice, val;
    while(1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}