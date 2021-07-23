#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    pid_t pid;
    pid = fork();
    switch(pid){

        case -1:

            perror("fork = -1\n");
            exit(-1);

        case 0:
            
            printf("It is childe\n");
            printf("My PID = %d\n", getpid());
            execl("./test", "test", NULL);
            exit(1);

        default:

            wait(NULL);
            printf("It is Parent\n");
            printf("My PID = %d\n", getpid());
    }
}
