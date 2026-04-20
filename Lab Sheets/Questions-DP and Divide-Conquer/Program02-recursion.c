#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a >= b) ? a : b; }

// freelancer developer's dilemma
// return max of the payment sum
int f(int i, int H, int payments[], int hours[]) {
    // base case
    // going from top to bottom
    if (i == 0) {
        if (hours[0] <= H)
            return payments[0];
        else
            return 0;
    }

    // not pick the job
    int notPick = f(i - 1, H, payments, hours);

    // pick the job
    int pick = 0;
    if (hours[i] <= H) {
        pick = f(i - 1, H - hours[i], payments, hours) + payments[i];
    }

    return max(notPick, pick);
}

int main() {
    int N, H;
    scanf("%d %d", &N, &H);

    // payments array
    int payments[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &payments[i]);
    }

    // hours array
    int hours[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &hours[i]);
    }

    printf("%d \n", f(N - 1, H, payments, hours));

    return 0;
}