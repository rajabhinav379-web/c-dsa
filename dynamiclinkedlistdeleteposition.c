#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {

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

void deleteAtPosition(int position) {

    if(head == NULL) {

        printf("\nLinked List is empty.\n");
        return;
    }

    struct Node* temp = head;

    if(position == 1) {

        head = temp->next;

        free(temp);

        printf("\nNode deleted successfully.\n");
        return;
    }

    for(int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {

        printf("\nInvalid Position.\n");
        return;
    }

    struct Node* nextNode = temp->next;

    temp->next = nextNode->next;

    free(nextNode);

    printf("\nNode deleted successfully.\n");
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

    int n, value, position;

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insert(value);
    }

    display();

    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    deleteAtPosition(position);

    display();

    return 0;
}