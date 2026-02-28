#include <stdio.h>
// deleting the last element of the array

void deleteLast(int* arr, int* n) {
	(*n)--;
}

int main() {
	int arr[5] = {12, 13, 14, 15, 16};
	int n = 5;
	deleteLast(arr, &n);

	for (int i = 0; i < n; i++) {
		printf("%d ", *(arr + i));
	}
	return 0;
}