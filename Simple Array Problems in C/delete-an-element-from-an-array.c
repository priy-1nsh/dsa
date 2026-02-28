// C arrays are static in size, so we can't remove the element from the array memory, but we
// logically delete the element by overwriting it and updating the size variable

#include <stdio.h>

void deleteKey(int *arr, int *n, int key)
{
    // find the key in the array arr
    int position = 0;
    while (arr[position] != key)
        position++;

    for (int j = position; j < (*n) - 1; j++)
    {
        *(arr + j) = *(arr + j + 1);
    }

    (*n)--;
}

int main()
{

    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;

    deleteKey(arr, &n, key);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}