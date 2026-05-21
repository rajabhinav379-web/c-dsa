#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {

    struct Node* newNode =
    (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL) {

        front = rear = newNode;
    }
    else {

        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue.\n", value);
}

void dequeue() {

    if(front == NULL) {

        printf("\nQueue Underflow.\n");
        return;
    }

    struct Node* temp = front;

    printf("\nDeleted element: %d\n", front->data);

    front = front->next;

    if(front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {

    if(front == NULL) {

        printf("\nQueue is empty.\n");
        return;
    }

    struct Node* temp = front;

    printf("\nQueue Elements:\n");

    while(temp != NULL) {

        printf("%d ", temp->data);

        temp = temp->next;
    }

    printf("\n");
}

int main() {

    int n, value;

    printf("How many elements do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        printf("Enter value %d: ", i);
        scanf("%d", &value);

        enqueue(value);
    }

    display();

    dequeue();

    display();

    return 0;
}