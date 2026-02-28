#include <stdio.h>

// inserting an element at the end
void insert(int *arr, int *n, int val)
{
    *(arr + (*n)) = val;
    (*n)++;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5};
    int n = 5;
    int val = 6;
    insert(arr, &n, val);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}