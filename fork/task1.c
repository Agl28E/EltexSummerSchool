#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
  pid_t pid, ppid;
  int rv = 0;
  pid = fork(); 
  if (pid == -1){
          perror("fork = -1"); /* произошла ошибка */
          exit(1); /*выход из родительского процесса*/
  } else {
      if (pid == 0){
          printf(" CHILD: Это процесс-потомок!\n");
          printf(" CHILD: Мой PID -- %d\n", getpid());
          printf(" CHILD: PID моего родителя -- %d\n", getppid());
          exit(rv);
     
  } else {
          printf("PARENT: Это процесс-родитель!\n");
          printf("PARENT: Мой PID -- %d\n", getpid());
          printf("PARENT: PID моего потомка %d\n", pid);
          printf("PARENT: Я жду, пока потомок не вызовет exit()...\n");
          wait(NULL);
  }
  }
return 0;
}
