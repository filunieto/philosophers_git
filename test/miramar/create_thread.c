#include <stdio.h>
#include <pthread.h>

#define NC "\e[0m"
#define YELLOW "\e[1;33m"
#define RED "\e[4;31m"

void *thread_routine(void *data)
{
	pthread_t tid;

	data = NULL;
	tid = pthread_self();
	printf("%sThread [%ld]: %s The heaviest burden is to exist without living.%s\n",YELLOW, tid, RED, NC);
	return(data);

}

int	main(void)
{
	pthread_t	tid1;	// First thread's ID
	pthread_t	tid2;	// Second thread's ID

	// Creating the first thread that will go
	// execute its thread_routine function.
	pthread_create(&tid1, NULL, thread_routine, NULL);
	printf("Main: Created first thread [%ld]\n", tid1);
	// Creating the second thread that will also execute thread_routine.
	pthread_create(&tid2, NULL, thread_routine, NULL);
	printf("Main: Created second thread [%ld]\n", tid2);
	// The main thread waits for the new threads to end
	// with pthread_join.
	pthread_join(tid1, NULL);
	printf("Main: Joining first thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Joining second thread [%ld]\n", tid2);
	return (0);
}