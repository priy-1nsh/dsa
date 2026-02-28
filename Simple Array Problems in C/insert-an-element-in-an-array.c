#include <stdio.h>

// inserting an element in an array at a given position

void insertElement(int *arr, int n, int pos, int val);

int main()
{

	int arr[6] = {1, 2, 3, 5, 6};

	int n = sizeof(arr) / sizeof(arr[0]);

	int pos = 3, val = 4;

	insertElement(arr, n, pos, val);

	// printing the new array
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}

void insertElement(int *arr, int n, int pos, int val)
{
	// shift the elements to the right from pos
	// hence we will loop from the end to the position pos
	for (int i = n - 1; i >= pos; i--)
	{
		*(arr + i + 1) = *(arr + i);
	}

	*(arr + pos) = val;
}