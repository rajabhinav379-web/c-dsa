# include <stdio.h>

int main() {
    int arr[5] = {64, 34, 25, 12, 22};
    int i, j, temp;

    printf("Before sorting:\n");

    for(i= 0; i < 5; i ++) {
        printf("%d", arr[i]);
    }
    for(i =0; i < 5 -1; i++) {
        for(j =0; j <5 -i-1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j +1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nAfter sorting:\n");

    for(i =0; i <5; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}