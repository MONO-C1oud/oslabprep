#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sighandler() {
	printf("I am the signal");
}

int main() {
	printf("Hello there!\n");
	signal(SIGINT, sighandler);
	while(1) {
		printf("Program running...\n");
		sleep(1);
	}
	return 0;
}