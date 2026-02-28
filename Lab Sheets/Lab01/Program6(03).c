// frequency counter - hashing based approach

#include <stdio.h>
#include <stdlib.h>



int main() {
    
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // find max and min element in the arr
    int min = arr[0], max = arr[0];
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    int range = max - min + 1;
    int hashArray[range];
    
    // intialize it with all zeros
    for (int i = 0; i < range; i++) {
        hashArray[i] = 0;
    }
    
    // hashing
    for (int i = 0; i < n; i++) {
        hashArray[arr[i] - min]++;
    }
    
    // print the result
    for (int i = 0; i < range; i++) {
        if (hashArray[i] != 0) {
            printf("%d -> %d\n", i+min, hashArray[i]);
        }
    }
    return 0;
}