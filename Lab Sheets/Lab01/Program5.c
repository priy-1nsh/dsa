#include <stdio.h>

int main() {
    int n1, n2;
    
    // get the info for arr1
    scanf("%d", &n1);
    int arr1[n1];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    // get the info for arr2
    scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    int i = 0, j = 0, k = 0;
    
    int result[n1+n2];
    
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k] = arr1[i];
            i++;
            k++;
        }
        else {
            result[k] = arr2[j];
            j++;
            k++;
        }
    }
    
    while (i < n1) {
        result[k] = arr1[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
    
    // printing the resulting array - result 
    for (int i = 0; i < (n1+n2); i++) {
        printf("%d ", result[i]);
    }
    
    return 0;
}