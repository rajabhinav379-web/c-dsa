#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// INSERT FUNCTION
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

    printf("%d inserted\n", value);
}

// DISPLAY FUNCTION
void display() {

    struct Node* temp = head;

    if(head == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("Linked List:\n");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// SEARCH FUNCTION
void search(int key) {

    struct Node* temp = head;
    int position = 1;
    int found = 0;

    while(temp != NULL) {

        if(temp->data == key) {
            printf("%d found at position %d\n", key, position);
            found = 1;
            break;
        }

        temp = temp->next;
        position++;
    }

    if(found == 0) {
        printf("%d not found in linked list\n", key);
    }
}

int main() {

    int n, value, key;

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        insert(value);
    }

    display();

    printf("Enter value to search: ");
    scanf("%d", &key);

    search(key);

    return 0;
}