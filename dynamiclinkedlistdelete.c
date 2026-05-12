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
    } else {
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

void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;

    if(temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);

        printf("Node deleted successfully.\n");
        return;
    }

    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found in linked list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted successfully.\n");
}

int main() {
    int n, value, deleteValue;

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insert(value);
    }

    display();

    printf("Enter value to delete: ");
    scanf("%d", &deleteValue);

    deleteNode(deleteValue);

    display();

    return 0;
}