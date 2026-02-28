// frequency counter - sorting based approach

#include <stdio.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int didSwap = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
}

int main() {
    
    // array size input
    int n;
    scanf("%d", &n);
    
    // array elements input
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // sort the array if it's not sorted
    bubbleSort(arr, n);
    
    // now we do the counting of the frequency
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i+1] &&  i < n-1) {
            count++;
        }
        else {
            printf("%d -> %d\n", arr[i], count);
        }
    }
    
    return 0;
}