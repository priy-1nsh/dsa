#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leftRotateByOne(int* arr, int n) {
    int temp = *(arr);
    for (int i = 0; i < n - 1; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    *(arr + n - 1) = temp;
}

void rightRotateByOne(int* arr, int n) {
    int temp = *(arr + n - 1);
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

void rotateLeft(int arr[], int k, int n) {
    k = k % n;
    for (int i = 0; i < k; i++) {
        leftRotateByOne(arr, n);
    }
}

void rotateRight(int arr[], int k, int n) {
    k = k % n;
    for (int i = 0; i < k; i++) {
        rightRotateByOne(arr, n);
    }
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int direction;
    scanf("%d", &direction);
    
    int k;
    scanf("%d", &k);
    
    if(direction == 0) {
        rotateLeft(arr, k, n);
    }
    
    if(direction == 1) {
        rotateRight(arr, k, n);
    }
    
    printArray(arr, n);
    return 0;
}