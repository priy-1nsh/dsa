#include <stdio.h>

void matrixMultiplication (int a, int b, int c, int matA[a][b], int matB[b][c], int matC[a][c]) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < c; j++) {
			matC[i][j] = 0;
			for (int k = 0; k < b; k++) {
				matC[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}
}

int main() {
	// getting dimensions of matA
	int a, b;
	int c, d;
	scanf("%d %d", &a, &b);

	int matA[a][b];

	// getting elements of matA
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &matA[i][j]);
		}
	}
	
	// getting dimensions of matB
	scanf("%d %d", &c, &d);

	int matB[c][d];

	// getting elements of matB
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < d; j++) {
			scanf("%d", &matB[i][j]);
		}
	}

	// check if the multiplication is possible
	if (b != c) {
		printf("Not Possible");
		return 0;
	}

	
	int matC[a][d];
	matrixMultiplication(a, b, d, matA, matB, matC);
	

	// print matC
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < d; j++) {
			printf ("%d ", matC[i][j]);
		}
		printf("\n");
	}
	return 0;
}