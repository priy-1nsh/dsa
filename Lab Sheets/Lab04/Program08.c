#include <stdio.h>

long long max(long long a, long long b)
{
    return (a > b) ? a : b;
}

int canPaint(int boards[], int n, int k, long long maxTime)
{
    long long currSum = 0;
    int painters = 1;

    for (int i = 0; i < n; i++)
    {
        if (boards[i] > maxTime)
            return 0;

        if (currSum + boards[i] <= maxTime)
        {
            currSum += boards[i];
        }
        else
        {
            painters++;
            currSum = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

long long minTime(int boards[], int n, int k)
{
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++)
    {
        low = max(low, boards[i]); // max board
        high += boards[i];         // sum of boards
    }

    long long ans = high;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid))
        {
            ans = mid;
            high = mid - 1; // try smaller max time
        }
        else
        {
            low = mid + 1; // need more time
        }
    }
    return ans;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &boards[i]);

    printf("%lld\n", minTime(boards, n, k));
    return 0;
}
