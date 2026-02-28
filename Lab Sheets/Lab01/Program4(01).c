#include <stdio.h>

// set operations - but it doesn't care about the duplicates in A

// findUnion function
void findUnion(int A[], int n1, int B[], int n2) {
    // print elements of A
    printf("Union: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", A[i]);
    }
    
    // now, print elements of B not in A
    for (int j = 0; j < n2; j++) {
        int found = 0;
        for (int i = 0; i < n1; i++) {
            if (B[j] == A[i]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            // not found - unique elements
            printf("%d ", B[j]);
        }
    }
    printf("\n");
}

void findIntersection(int A[], int n1, int B[], int n2) {
    int foundAny = 0;
    // only print the common elements and if there are none, print none
    printf("Intersection: ");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                foundAny = 1;
                break;
            }
        }
    }
    if (foundAny == 0) {
        printf("(None)");
    }
}

int main() {
    
    int N1, N2;
    
    // take array A size
    scanf("%d", &N1);
    int A[N1];
    // accept elements of A
    for (int i = 0; i < N1; i++) {
        scanf("%d", (A + i));
    }
    
    // take array B size
    scanf("%d", &N2);
    int B[N2];
    // accept elements of B
    for (int i = 0; i < N2; i++) {
        scanf("%d", (B + i));
    }
    
    findUnion(A, N1, B, N2);
    findIntersection(A, N1, B, N2);
        
    return 0;
}