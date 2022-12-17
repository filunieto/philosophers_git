#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>



int	main()
{
	int pid;

	pid = fork();
	if (pid == -1)
		return 1;
	if (!pid)
	{
		sleep(3);
		printf("hello from process CHILD 0?: |%i|\n", pid);
	}
	if (pid != 0) //parent 
	{
		printf("hello from process parewnt?: |%i|\n", pid);
		wait(NULL);
	}
	return (0);
}
