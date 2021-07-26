#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main() {

    int fd[2];
    //fd[0] - read
    //fd[1] - write
    if (pipe(fd) == -1){
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }
    
    int id = fork();

    if (id == -1) {
        printf("An error occured with fork\n");
        return 4;
    }

    if (id == 0) { 
        close(fd[0]);
        char str[200];
        printf("Input string: ");
        fgets(str, 200, stdin);
        str[strlen(str) - 1] = '\0';
        
        int n = strlen(str) + 1;
        if (write(fd[1], &n, sizeof(int)) < 0) {
            return 5;
        }


        if (write(fd[1], str, sizeof(char) * n) == -1) {
            printf("An error ocurred with writing to the pipe\n");
            return 2;
        }
        close(fd[1]);

    } else {
        close(fd[1]);
        char str[200];
        int n;
        if (read(fd[0], &n, sizeof(int)) < 0) {
            return 6;
        }
        if (read(fd[0], str, sizeof(char) * n) == -1) {
            printf("An error ocurred with reading from the pipe\n");
            return 3;
        }
        close(fd[0]);
        printf("Got from childe process %s\n", str);
        wait(NULL);
    }

    return 0;
}
