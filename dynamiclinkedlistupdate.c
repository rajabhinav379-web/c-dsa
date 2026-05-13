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

void updateNode(int oldValue, int newValue) {

    struct Node* temp = head;
    int found = 0;

    while(temp != NULL) {

        if(temp->data == oldValue) {
            temp->data = newValue;
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if(found) {
        printf("\nNode updated successfully.\n");
    } else {
        printf("\nValue not found in linked list.\n");
    }
}

int main() {

    int n, value;
    int oldValue, newValue;

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insert(value);
    }

    display();

    printf("\nEnter value to update: ");
    scanf("%d", &oldValue);

    printf("Enter new value: ");
    scanf("%d", &newValue);

    updateNode(oldValue, newValue);

    display();

    return 0;
}