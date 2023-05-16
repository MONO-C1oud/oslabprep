#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <pthread.h>

int main() {
	int r1 = 3, c1 = 3, r2 = 3, c2 = 3;
	int* a1 = (int *)malloc(r1 * c1 * sizeof(int));
	int* a2 = (int *)malloc(r2 * c2 * sizeof(int));
	int* result = (int *)malloc(r1 * c2 * sizeof(int));
	printf("Matrix 1:\n");
	int a = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(a1 + i*c1 + j) = a;
			printf("%d ", *(a1 + i*c1 + j));
			a++;
		}
		printf("\n");
	}
	printf("\n");
	printf("Matrix 2:\n");
	a = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(a2 + i*c2 + j) = a;
			printf("%d ", *(a2 + i*c2 + j));
			a++;
		}
		printf("\n");
	}
	printf("\n");
	printf("Result:\n");
	#pragma omp parallel num_threads(10)
	#pragma omp for
		for (int i = 0; i < r1; i++) {
			for (int j = 0; j < c2; j++) {
				for (int k = 0; k < c1; k++) {
					*(result + i*c2 + j) += *(a1 + i*c1 + k) * *(a2 + k*c2 + j);
				}
			}
		}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", *(result + i*c2 + j));
		}
		printf("\n");
	}


}