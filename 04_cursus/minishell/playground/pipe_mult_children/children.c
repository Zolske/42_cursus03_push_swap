#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CHILDREN 3

int main( void )
{
    pid_t pid;

    int fd[2];


    char str[] = "Hello";

    for(int num_process = 0; num_process < MAX_CHILDREN; num_process++)
    {
        if(pipe(fd) == -1)
        {
            perror( "pipe Failed" );
            continue;
        }

        pid = fork();

        if(pid < 0)
        {
            perror("fork failed");
            exit(1);
        }

        if(pid == 0)
        { //child code
            char buff[50];
            printf("Child %i (pid= %i)\n", num_process, getpid());
            close(fd[1]);

            if ( read( fd[0], buff, sizeof(buff)) <= 0) //read from pipe
            {
                perror( "read failed" );
                exit( EXIT_FAILURE );
            }

            printf("Read child = %s\n", buff);
            exit(0);
        }

        else{//parent
            printf("Im parent %i\n",getpid());
            close(fd[0]);
            write(fd[1], str,strlen(str)+1);
            printf("Parent send %s\n", str);
            wait(NULL);
        }
    }

    return 0;
}