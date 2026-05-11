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

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    }

    else {

        struct Node* temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("%d inserted\n", value);
}

void display() {

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    printf("\nCircular Linked List:\n");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    while(temp != head);

    printf("\n");
}

int main() {

    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insert(value);
    }

    display();

    return 0;
}