#include <stdio.h>
#include <math.h>

// // left-rotate an array by d places - approach 1
// // d times left-rotate the array by one place
int min(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int gcd(int a, int b)
{
    int c = min(a, b);
    for (int i = c; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

void leftRotateByD(int *arr, int d, int n);
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}

// void leftRotateByOne(int *arr, int n)
// {
//     // left rotate the array by one place
//     int i = 0;
//     int temp = arr[i];
//     while (i < n)
//     {
//         arr[i] = arr[i + 1];
//         i++;
//     }
//     arr[n - 1] = temp;
// }

// void leftRotateByD(int *arr, int d, int n)
// {
//     for (int i = 0; i < d; i++)
//     {
//         leftRotateByOne(arr, n);
//     }
// }

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int n = 18, d = 3;
    leftRotateByD(arr, d, n);
    printArray(arr, n);
}

// another approach
// rotating in the cycled of gcd(d, n)
void leftRotateByD(int *arr, int d, int n)
{
    if (d >= n)
    {
        d = d % n;
    }

    int g_c_d = gcd(d, n); // number of cycles
    for (int i = 0; i < g_c_d; i++)
    {
        int temp = arr[i];
        int j = i;
        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}