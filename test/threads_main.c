#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void	*routine()
{
	void *ptr = NULL;
	printf("Hello from threads1\n");
	sleep(3);
	printf("END from threads1\n");
	return (ptr);
}


void	*routine2()
{
	void *ptr = NULL;
	printf("Test from threads2\n");
	sleep(3);
	printf("END from threads2\n");
	return (ptr);
}


int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine, NULL))
		return 1;
	if (pthread_create(&t2, NULL, &routine2, NULL))
		return 2;
	if (pthread_join(t1, NULL))
		return 3;
	if (pthread_join(t2, NULL))
		return 4;
	//pthread_join(t2, NULL);
	return (0);
}
