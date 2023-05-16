#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int pid = 0;
	int i = 0;
	while (i < 1) {
		pid = fork();
		printf ("\n\n%d fork call\n\n", i);
		if (pid > 0) { //parent process
			printf("BAAP\n");
			printf("BAAP pid = %d\n", getpid());
			printf("Baap ke peyo ki pid = %d\n", getppid());
			printf("baap bachay ka intezar karte huay...\n");
			wait(); //baap intezar farmatey huay
			printf("Wafaat moment\n");
		}
		else if (pid == 0) { //child process
			printf("beta\n");
			printf("Beta pid = %d\n", getpid());
			printf("Peyo ki pid = %d\n", getppid());
			sleep(5);
			printf("abba mera kaam ho gaya lol\n");
		}
		i++;
	}
	return 0;
}