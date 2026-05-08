#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if((rear + 1) % SIZE == front) {
        printf("Queue overflow\n");
    }else {
        if(front == -1)
        front =0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("%D inserted\n",value);
    }
}
void dequeue() {
    if(front == -1) {
        printf("Queue underflow\n");
    }else {
        printf("%d deleted\n",queue[front]);
        if(front == rear) {
            front = rear = -1 ;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue element are:\n");

        int i = front;

        while(i != rear){
            printf("%d\n", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    display();

    display();

    return 0;
}