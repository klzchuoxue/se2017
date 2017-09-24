#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid==0)
		printf("Child process\n");
	else if(pid >0)
		printf("Parent process\n");
	else
		printf("fork failure\n");
	exit(0);
}
