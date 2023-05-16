#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m1;

typedef struct {
	int x;
	int y;
} jugaar;

void hello(void* j1) {
	jugaar* j2 = (jugaar *)j1;
	printf("x = %d, y = %d\n", j2->x, j2->y);
}

int main() {
	pthread_mutex_init(&m1, 0);
	jugaar j1;
	pthread_t t[5];
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {11, 22, 33, 44, 55};
	for (int i = 0; i < 5; i++) {
		j1.x = a[i];
		j1.y = b[i];
		pthread_create(&t[i], NULL, hello, (void *)&j1);
	}
	for (int i = 0; i < 5; i++) {
		pthread_join(t[i], NULL);
	}
	pthread_mutex_destroy(&m1);
}