#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

// given function
long long functionValue(int x)
{
    return 2LL * x * x * x - 1LL * x * x + 5LL * x;
}

int searchLargest(long long y)
{
    int low = 0, high = 100000; // safer range
    int ans = -1;               // initialize

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long value = functionValue(mid);

        if (value <= y)
        {
            ans = mid;     // valid candidate
            low = mid + 1; // try for larger x
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    // reading inputs as string because of commas in the input
    char s[20];
    scanf("%s", s);

    char clean[20];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ',')
        {
            clean[j] = s[i];
            j++;
        }
    }

    clean[j] = '\0';

    long long y = atoll(clean);

    int ans = searchLargest(y);
    printf("%d\n", ans);

    return 0;
}
