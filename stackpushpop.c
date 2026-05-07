#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value) {
    if(top == SIZE -1){
        printf("Stack Overflow\n");
    }else {
        top++;
        stack[top] = value;
        printf("%d pushed\n", value);
    }
}
void pop(){
    if(top == -1) {
        printf("stack undeflow\n");
    }else {
        printf("%d popped\n", stack[top]);
        top--;
    }
}
void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    }else {
        printf("Stack element are:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}