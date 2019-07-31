#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	// Fork returns process id
	// in parent process
	printf("The process id is %d\n", getpid());
	pid_t child_pid = fork();


	// Parent process
	if (child_pid > 0){
		printf("The parent process id is %d\n", getpid());
		printf("The parent is now sleeping.\n");
		sleep(3);
	}

	// Child process
	else{
		printf("The child process id is %d\n", getpid());
		printf("The child is now exiting.\n");
		exit(0);
	}

	printf("The zombie child process id is %d\n", child_pid);

	return 0;
}
