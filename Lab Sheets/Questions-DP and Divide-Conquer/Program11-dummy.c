#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// structure to store multiple results
typedef struct {
    long long values[MAX];
    int size;
} Result;

// function to apply operator
long long applyOp(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;  // op == '*'
}

// recursive function
Result solve(char* exp, int start, int end) {
    Result res;
    res.size = 0;

    // check if substring is a number
    int isNumber = 1;
    for (int i = start; i <= end; i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            isNumber = 0;
            break;
        }
    }

    // base case: single number
    if (isNumber) {
        long long num = exp[start] - '0';  // single digit
        res.values[res.size++] = num;
        return res;
    }

    // try every operator as partition point
    for (int i = start; i <= end; i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            // divide
            Result left = solve(exp, start, i - 1);
            Result right = solve(exp, i + 1, end);

            // combine
            for (int l = 0; l < left.size; l++) {
                for (int r = 0; r < right.size; r++) {
                    long long val =
                        applyOp(left.values[l], right.values[r], exp[i]);
                    res.values[res.size++] = val;
                }
            }
        }
    }

    return res;
}

// comparator for sorting
int cmp(const void* a, const void* b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    char exp[25];
    scanf("%s", exp);

    Result ans = solve(exp, 0, n - 1);

    // sort results
    qsort(ans.values, ans.size, sizeof(long long), cmp);

    // print results
    for (int i = 0; i < ans.size; i++) {
        printf("%lld ", ans.values[i]);
    }

    printf("\n");

    return 0;
}