#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	// Create a child process
	int pid = fork();

	if (pid > 0){
		printf("We are in parent process\n");
		printf("The parent process id is %d\n", getpid());
	}

	// Note that pid is 0 in child process
	// and negative if fork() fails
	else if (pid == 0)
	{
		sleep(1);
		printf("We are in child process\n");
		printf("The child process id is %d\n", getpid());
		printf("The new parent process id is %d\n", getppid());
		return 0;
	}

	return 0;
}
