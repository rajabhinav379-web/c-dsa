#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {

        struct Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display() {

    struct Node* temp = head;

    printf("\nLinked List:\n");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void reverseList() {

    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while(current != NULL) {

        next = current->next;

        current->next = prev;

        prev = current;

        current = next;
    }

    head = prev;

    printf("\nLinked List Reversed Successfully.\n");
}

int main() {

    int n, value;

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insert(value);
    }

    printf("\nOriginal ");
    display();

    reverseList();

    printf("\nReversed ");
    display();

    return 0;
}