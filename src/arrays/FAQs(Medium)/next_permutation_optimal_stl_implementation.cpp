#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& a) {
    int n = a.size();
    // finding the next permutation is same as finding the "just next greater element" since this next permutation thing is like dictionary

    // 1. We find the breakpoint from the end
    int ind = -1;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] < a[i+1]) {
            ind = i;
            break;
        }
    }

    // edge case : no breakpoint exists : which means the given arr a is the last permutation in the line : so we just return the first permutation as the next permutation
    if (ind == -1) {
        reverse(a.begin(), a.end());
        return a;
    }

    // 2. Now, we find the elt greater than the ith elt , which is just greater than the ith element to exchange places with iin order to get the immediate next greater number
    for (int i = n-1; i > ind; i--) {
        if (a[i] > a[ind]) {
            swap(a[i], a[ind]);
            break;
        }
    }

    // 3. Now, just sort the remaining array a from ind+1 to the n-1
    reverse(a.begin() + ind + 1, a.end());
    return a;
}

int main() {
    return 0;
}