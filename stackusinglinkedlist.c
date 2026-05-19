#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {

    struct Node* newNode =
    (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    printf("%d pushed into stack.\n", value);
}

void pop() {

    if(top == NULL) {

        printf("\nStack Underflow.\n");
        return;
    }

    struct Node* temp = top;

    printf("\nDeleted element: %d\n", top->data);

    top = top->next;

    free(temp);
}

void display() {

    if(top == NULL) {

        printf("\nStack is empty.\n");
        return;
    }

    struct Node* temp = top;

    printf("\nStack Elements:\n");

    while(temp != NULL) {

        printf("%d\n", temp->data);

        temp = temp->next;
    }
}

int main() {

    int n, value;

    printf("How many elements do you want to push: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        push(value);
    }

    display();

    pop();

    display();

    return 0;
}