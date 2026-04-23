#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// insert function
// initially this function is called with i = 0
void insertContainer(int hashTable[], int id, int m, int index) {
    // id = container id

    // if the current index is empty
    if (hashTable[index] == -1) {
        hashTable[index] = id;
        return;
    }

    if (hashTable[index] < 1000 && id >= 1000) {
        int kicked = hashTable[index];
        hashTable[index] = id;
        // now, we will insert the hashTable[index] key at a new location
        insertContainer(hashTable, kicked, m, (index + 1) % m);
        return;
    }

    // in all the other cases - just go to the next index
    insertContainer(hashTable, id, m, (index + 1) % m);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // create a hashTable of size = number of bays
    int hashTable[m];

    // initialise all the empty slots with -1
    for (int i = 0; i < m; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int start = arr[i] % m;
        insertContainer(hashTable, arr[i], m, start);
    }

    // print the final hashTable
    for (int i = 0; i < m; i++) {
        printf("%d ", hashTable[i]);
    }

    return 0;
}