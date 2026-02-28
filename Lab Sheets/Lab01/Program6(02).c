// frequency counter

#include <stdio.h>

int maxElement(int* arr, int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    
    int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};
    int n = 8;
    
    int max = maxElement(arr, n);
    int visited[max+1];
    for (int i = 0; i <= max; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        visited[arr[i]]++;
    }
    
    // printing frquency
    for (int i = 0; i < max + 1; i++) {
        if (visited[i] != 0) {
            printf("%d -> %d\n", i, visited[i]);
        }
    }
    
    return 0;
}