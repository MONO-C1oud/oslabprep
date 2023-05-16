#include <signal.h>
#include <stdio.h>

int main() {
	int pid = 62790;
	int sig = SIGINT;
	int x = kill(pid, sig); /* Send the signal to the named process */
	printf("%d",x);
	return 0;
}