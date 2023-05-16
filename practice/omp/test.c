#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <omp.h>
#include <pthread.h>

int main() {
	#pragma omp parallel num_threads(10)
	printf("Hello world!\n");

	


}