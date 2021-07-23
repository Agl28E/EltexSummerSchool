#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	pid_t idpid1, idpid2, idpid11, idpid12, idpid21;
	idpid1 = fork();
	if (idpid1 == -1){
		printf ("Error with fork\n");
		return 0;
	} else {
		if (idpid1 == 0){
			printf ("Branch 1. Level 1, pid = %d, ppid = %d\n", getpid(), getppid());
			idpid11 = fork();
			if (idpid11 == 0){
				printf ("Branch 1. Level 2 1., pid = %d, ppid = %d\n",
				getpid(), getppid());
                wait(NULL);
			} else {
				idpid12 = fork();
				if (idpid12 == 0){
				printf ("Branch 1. Level 2 2., pid = %d, ppid = %d\n",
				getpid(), getppid());
				}
				wait(NULL);
			}
		} else {
			printf ("Parent, pid = %d, ppid = %d\n", getpid(), getppid());
			idpid2 = fork();
			if (idpid2 == 0){
				printf ("Branch 2. Level 1, pid = %d, ppid = %d\n", getpid(), getppid());
				idpid21 = fork();
				if (idpid21 == 0){
					printf ("Branch 2. Level 2, pid = %d, ppid = %d\n", getpid(), getppid());
				}
			}
			wait(NULL);
            wait(NULL);
		}
	}
}
