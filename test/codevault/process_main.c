#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>



int	main()
{
	int pid;
	int x = 2;

	pid = fork();
	if (pid == -1)
		return 1;
	if (!pid)
	{
		x++;
		sleep(3);
		printf("hello from process CHILD 0?: |%i|\n", pid);
		printf("Process ID in child: |%i|\n", getpid());
	}
	sleep(2);
	printf("value of x: |%i|\n", x);
	//printf("Process ID: |%i|\n", getpid());
	if (pid != 0) //parent 
	{
		printf("hello from process parewnt?: |%i|\n", pid);
		printf("Process ID in parent: |%i|\n", getpid());
		wait(NULL);
	}
	printf("antes d erturn\n");
	return (0);
}
