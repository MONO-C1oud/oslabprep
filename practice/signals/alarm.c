#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sighand() {
	printf("Ding ding ding\n");
}

int main ( )
{
	//alarm (5) ; /* schedule an alarm signal in 5 seconds */
	signal(SIGALRM, sighand);
	printf ("Looping forever ...\n") ;
	alarm(5);
	while ( 1 ) ;
	printf ("This line shouldn't execute...\n");
	return 0;
}