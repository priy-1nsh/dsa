class Solution {
    private:
    long long nCr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n-i);
            res = res / (i+1);
        }
        return res;
    }
public:
    int pascalTriangleI(int r, int c) {
        return nCr(r-1, c-1);
    }
};