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

void sortList() {

    struct Node *current, *index;
    int temp;

    if(head == NULL) {
        return;
    }

    for(current = head; current->next != NULL; current = current->next) {

        for(index = current->next; index != NULL; index = index->next) {

            if(current->data > index->data) {

                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    printf("\nLinked List Sorted Successfully.\n");
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

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insert(value);
    }

    printf("\nBefore Sorting");
    display();

    sortList();

    printf("\nAfter Sorting");
    display();

    return 0;
}