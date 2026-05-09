#include <stdio.h>

int main() {
    int arr[5] ={64, 25, 12, 22, 11};
    int i, j, minIndex, temp;
    printf("Before sirting:\n");

    for(i =0; i < 5; i ++) {
        printf("%d ", arr[i]);
    }
    for(i = 0; i < 5 - 1; i++) {
        minIndex = i;

        for(j = i +1; j < 5; j++) {
            if(arr[j] < arr[minIndex]){
                minIndex =j;
            }
             
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    printf("\nAfter sorting:\n");

    for(i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}