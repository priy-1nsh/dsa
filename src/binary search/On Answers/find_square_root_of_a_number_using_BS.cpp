class Solution {
public:
    int floorSqrt(int n)  {
        int l = 1, h = n;
        int ans = -1;
        while (l <= h) {
            int m = (l+h) / 2;
            if (m*m <= n) {
                l = m + 1;
                ans = m;
            }
            else {
                h = m - 1;
            }
        }
        return ans;
    }
};