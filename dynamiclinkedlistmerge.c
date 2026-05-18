#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

void insertList1(int value) {

    struct Node* newNode =
    (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head1 == NULL) {
        head1 = newNode;
    }
    else {

        struct Node* temp = head1;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertList2(int value) {

    struct Node* newNode =
    (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head2 == NULL) {
        head2 = newNode;
    }
    else {

        struct Node* temp = head2;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display(struct Node* head) {

    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void mergeLists() {

    if(head1 == NULL) {
        head1 = head2;
        return;
    }

    struct Node* temp = head1;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;
}

int main() {

    int n1, n2, value;

    printf("How many nodes for List 1: ");
    scanf("%d", &n1);

    for(int i = 1; i <= n1; i++) {

        printf("Enter value %d for List 1: ", i);
        scanf("%d", &value);

        insertList1(value);
    }

    printf("\nHow many nodes for List 2: ");
    scanf("%d", &n2);

    for(int i = 1; i <= n2; i++) {

        printf("Enter value %d for List 2: ", i);
        scanf("%d", &value);

        insertList2(value);
    }

    printf("\nList 1:\n");
    display(head1);

    printf("\nList 2:\n");
    display(head2);

    mergeLists();

    printf("\nMerged Linked List:\n");
    display(head1);

    return 0;
}