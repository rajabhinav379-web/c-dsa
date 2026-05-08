#include <stdio.h>

int main () {
    int arr[] = {10,20,30,40,50};
    int low =0;
    int high =4;
    int mid;
    int key =30;
    int found =0;

    while(low<= high) {
        mid = (low + high)/2;

        if(arr[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found =1;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid -1;
        }
    }
    if (found == 0) {
        printf("Element not found");
    }
    return 0;
}