class Solution {
   public:
    int sumofdigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num = num / 10;
        }
        return sum;
    }
    int largestInteger(int n, int s) {
        // biggest number with n digits is 999.. n times
        int start = 0;
        for (int i = 0; i < n; i++) {
            start = start * 10 + 9;
        }

        while (start >= 0) {
            if (sumofdigits(start) == s) return start;
            start--;
        }

        return -1;
    }
};