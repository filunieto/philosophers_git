#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex_fuel;
int fuel = 0;
void	*fuel_filling(void *arg)
{
	printf("Fillng fuel\n");
	void *ptr = NULL;
	arg = ptr;
	return (arg);
}

void	*car(void *arg)
{
	printf("Car here to get fuel\n");
	void *ptr = NULL;
	arg = ptr;
	return (arg);
}

int main()
{
	pthread_t th[2];
	pthread_mutex_init(&mutex_fuel, NULL);
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
				perror("Failed to create thread\n");
		}
		else
		{
			if (pthread_create(&th[i], NULL, &car, NULL) != 0)
				perror("Failed to create thread\n");
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread\n");
	}
	pthread_mutex_destroy(&mutex_fuel);
	return (0);
}