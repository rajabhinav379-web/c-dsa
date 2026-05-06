#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front =-1, rear =-1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue overflow\n");
    }else {
        if (front == -1)
        front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted\n",value);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    }else {
        printf("Queue elements are:\n");

        for (int i = front; i <= rear; i++)

        {
            printf("%d", queue[i]);
        }
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    return 0;
    
}