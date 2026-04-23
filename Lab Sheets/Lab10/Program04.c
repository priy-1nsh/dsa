#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, R;
    scanf("%d %d", &M, &R);

    int N;
    scanf("%d", &N);

    int keys[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &keys[i]);
    }

    int hashTable[M];
    // initialize hashTable with -1
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        int key = keys[i];

        // primary hash function
        int h1 = key % M;

        // secondary hash function
        int h2 = R - (key % R);

        // start from the index 0 and can maximum go till m-1
        for (int i = 0; i < M; i++) {
            int probe = (h1 + (i * h2)) % M;  // ampersand makes it circular
            if (hashTable[probe] == -1) {
                // insert
                hashTable[probe] = key;
                break;  // if inserted, no need to check more indexes i
            }
        }
    }

    // print the final hashTable
    for (int i = 0; i < M; i++) {
        printf("%d ", hashTable[i]);
    }

    return 0;
}