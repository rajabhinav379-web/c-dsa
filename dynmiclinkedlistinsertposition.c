#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int value) {

    struct Node* newNode =
    (struct Node*)malloc(sizeof(struct Node));

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

void insertAtPosition(int value, int position) {

    struct Node* newNode =
    (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if(position == 1) {

        newNode->next = head;
        head = newNode;

        return;
    }

    struct Node* temp = head;

    for(int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("\nInvalid Position.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("\nNode inserted successfully.\n");
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

int main() {

    int n, value;
    int newValue, position;

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insertEnd(value);
    }

    display();

    printf("\nEnter new value to insert: ");
    scanf("%d", &newValue);

    printf("Enter position: ");
    scanf("%d", &position);

    insertAtPosition(newValue, position);

    display();

    return 0;
}