#include <stdio.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int arr[100];
    int queries[100];

    // input the N elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // input the Q search queries
    for (int i = 0; i < Q; i++) {
        scanf("%d", &queries[i]);
    }

    /* ---------------------------------------------------
       STEP 1: SORT THE ARRAY
       We are not using qsort.
       We use bubble sort because it is easy to write.
       --------------------------------------------------- */
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    /* ---------------------------------------------------
       STEP 2: BUILD LEVELS OF THE DETERMINISTIC SKIP LIST

       level 0 -> every 1st element  -> all elements
       level 1 -> every 2nd element
       level 2 -> every 4th element
       level 3 -> every 8th element
       and so on...

       levels[i][j] = j-th element of i-th level
       size[i] = number of elements in i-th level
       --------------------------------------------------- */

    int levels[20][100];  // enough for small lab inputs
    int size[20];         // size of each level
    int totalLevels = 0;  // how many levels we made

    int step = 1;  // level 0 takes every 1st element

    while (step <= N) {
        int count = 0;

        // take elements at index 0, step, 2*step, 3*step, ...
        for (int i = 0; i < N; i = i + step) {
            levels[totalLevels][count] = arr[i];
            count++;
        }

        size[totalLevels] = count;
        totalLevels++;

        step = step * 2;  // next level skips more elements
    }

    /* ---------------------------------------------------
       STEP 3: PROCESS EACH QUERY
       --------------------------------------------------- */
    for (int q = 0; q < Q; q++) {
        int X = queries[q];

        // start from top-most level
        int level = totalLevels - 1;

        // start from first element of that level
        int pos = 0;

        // counts number of right/down moves
        int steps = 0;

        // to know whether X was found
        int found = 0;

        while (level >= 0) {
            /* --------------------------------------------
               MOVE RIGHT while:
               - there is a next element in same level
               - and next element <= X
               -------------------------------------------- */
            while (pos + 1 < size[level] && levels[level][pos + 1] <= X) {
                pos++;
                steps++;
            }

            /* --------------------------------------------
               CHECK if current element is X
               -------------------------------------------- */
            if (levels[level][pos] == X) {
                printf("%d", steps);
                found = 1;
                break;
            }

            /* --------------------------------------------
               MOVE DOWN to next lower level
               When we go down, the position changes.

               Why pos = pos * 2 ?

               Example:
               Level 2: 10   50
               positions: 0   1

               Level 1: 10 30 50
               positions: 0  1  2

               If we are at position 1 in Level 2 (value 50),
               then in Level 1 the same value is at position 2.

               So position roughly doubles.
               -------------------------------------------- */
            level--;

            if (level >= 0) {
                pos = pos * 2;
                steps++;
            }
        }

        // if not found in any level
        if (!found) {
            printf("-1");
        }

        // spacing between answers
        if (q != Q - 1) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}