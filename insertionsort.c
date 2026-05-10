#include <stdio.h>

int main () {
    int arr[5] = {64,25,12,22,11};
    int i, j, key;
    printf("Before sorting:\n");

    for(i =0; i <5; i++) {
        printf("%d ", arr[i]);
    }
    for(i = 1; i<5;i ++) {
        key =arr[i];
        j = i -1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("\nAfter sorting:\n");

    for(i = 0; i <5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}