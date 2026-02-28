#include <bits/stdc++.h>
using namespace std;

// armstrong number
class Solution
{
private:
    int countDigits(int num)
    {
        int count = 0;
        while (num > 0)
        {
            count++;
            num = num / 10;
        }
        return count;
    }

public:
    bool isArmstrong(int num)
    {
        int count = countDigits(num);
        int sum = 0;
        int copy = num;
        while (num > 0)
        {
            int lastDigit = num % 10;
            sum += (pow(lastDigit, count));
            num = num / 10;
        }
        return (sum == copy);
    }
};

int main()
{
    int num = 153;
    Solution sol;
    bool ans = sol.isArmstrong(num);
    if (ans)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}