#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(long long* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap(arr[j], arr[j+1])
                long long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ways to add parentheses
#define MAX 1000

typedef struct Result {
    long long values[MAX];
    int size;
} Result;

long long applyOp(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-')
        return a - b;
    else
        return a * b;
}

// recursive function - try all the ways - insert parentheses
Result solve(char* exp, int start, int end) {
    Result res;
    res.size = 0;

    // base case - single number
    // check for number
    int isNumber = 1;
    for (int i = start; i <= end; i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            isNumber = 0;
            break;
        }
    }

    if (isNumber) {
        long long num = exp[start] - '0';
        res.values[res.size] = num;
        res.size++;
        return res;
    }

    // do all the stuff
    for (int i = start; i <= end; i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            // divide
            Result left = solve(exp, start, i - 1);
            Result right = solve(exp, i + 1, end);

            // combine left and right using the operator at exp[i]
            for (int l = 0; l < left.size; l++) {
                for (int r = 0; r < right.size; r++) {
                    long long val =
                        applyOp(left.values[l], right.values[r], exp[i]);
                    res.values[res.size] = val;
                    res.size++;
                }
            }
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    char s[n + 1];
    scanf("%s", s);

    Result ans = solve(s, 0, n - 1);

    // sort the results - sort the ans.values array
    bubbleSort(ans.values, ans.size);

    // print the result
    for (int i = 0; i < ans.size; i++) {
        printf("%lld ", ans.values[i]);
    }
    printf("\n");
}