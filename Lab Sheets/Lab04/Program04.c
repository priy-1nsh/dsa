#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// where is groot
// largest integer X for which X*X <= K

long long searchLargest(long long K)
{
    long long low = 0, high = K;
    long long ans = -1;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long value = mid * mid;
        if (value <= K)
        {
            ans = mid;
            // search for the largest
            low = mid + 1;
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
    long long K;
    scanf("%lld", &K);

    int ans = searchLargest(K);

    printf("%lld", ans);

    return 0;
}