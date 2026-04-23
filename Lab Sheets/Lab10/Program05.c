#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
HashTable of size m with linear probing
To insert : find the hash, go to that index, if -1 or -2, insert there,
otheriwise newIndex = (index+1) % m To search : find hash, go to that index, if
matches, found, if doesn't match, go to the next slot, if it's -2 or something
else other than -1, continue past it if reach -1, not found To delete : first
search for the key and then put -2 if found
*/

void insert(int hashTable[], int m, int key) {
    for (int i = 0; i < m; i++) {
        int index = ((key % m) + i) % m;
        if (hashTable[index] == -1 || hashTable[index] == -2) {
            hashTable[index] = key;
            return;
        }
        // else if anything else, move to the next i
    }
}

int search(int hashTable[], int m, int key) {
    for (int i = 0; i < m; i++) {
        int index = ((key % m) + i) % m;
        if (hashTable[index] == key) {
            return 1;
        }
        if (hashTable[index] == -1) {
            // we reached the first empty slot so not found
            return 0;
        }
        // else in all other cases, key not matching or -2, continue
    }
    return 0;
}

void deleteKey(int hashTable[], int m, int key) {
    for (int i = 0; i < m; i++) {
        int index = ((key % m) + i) % m;
        if (hashTable[index] == key) {
            hashTable[index] = -2;
            return;
        }
        if (hashTable[index] == -1) {
            return;  // not found
        }
    }
}

int main() {
    int m, q;
    scanf("%d %d", &m, &q);

    // hashTable
    int hashTable[m];
    // intialize with -1
    for (int i = 0; i < m; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < q; i++) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int key;
            scanf("%d", &key);
            // insert
            insert(hashTable, m, key);
        }

        else if (choice == 2) {
            int key;
            scanf("%d", &key);
            // delete
            deleteKey(hashTable, m, key);
        }

        else if (choice == 3) {
            int key;
            scanf("%d", &key);
            // search
            if (search(hashTable, m, key)) {
                printf("Found\n");
            } else {
                printf("Not Found\n");
            }
        }
    }

    // print the whole hashTable
    for (int i = 0; i < m; i++) {
        printf("%d ", hashTable[i]);
    }

    return 0;
}