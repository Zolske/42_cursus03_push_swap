
// C++ program to demonstrate creating processes using fork() 
#include <unistd.h> 
#include <stdio.h> 
  
int main() 
{ 
	int fd[2];
	// initiate pipe
	if(pipe(fd) == -1)
	{
        printf("\nError: Could not create a pipe!\n");
        exit(-1);
    }
    // Creating first child 
    int n1 = fork(); 
  
    // Creating second child. First child 
    // also executes this line and creates 
    // grandchild. 
    int n2 = fork(); 
  
    if (n1 > 0 && n2 > 0) { 
        printf(">>> parent\n"); 
        // printf("%d %d \n", n1, n2); 
        // printf(" my id is %d \n", getpid()); 
    } 
    else if (n1 == 0 && n2 > 0) 
    { 
        printf(">>> First child\n"); 
        // printf(">>> %d %d \n", n1, n2); 
        // printf(">>> my id is %d  \n", getpid()); 
    } 
    else if (n1 > 0 && n2 == 0) 
    { 
        printf(">>> Second child\n"); 
        // printf(">>> %d %d \n", n1, n2); 
        // printf(">>> my id is %d  \n", getpid()); 
    } 
    else if (n1 == 0 && n2 == 0){ 
        printf(">>> third child\n"); 
        // printf(">>> %d %d \n", n1, n2); 
        // printf(">>>  my id is %d \n", getpid()); 
    } 
    return 0; 
} 