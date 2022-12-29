#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex_fuel;
int fuel = 0;
void	*fuel_filling(void *arg)
{
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_lock(&mutex_fuel);
		fuel = fuel + 15;
		printf("Fillng this much fuel: %d\n", fuel);
		pthread_mutex_unlock(&mutex_fuel);
		sleep(1);
	}
	void *ptr = NULL;
	arg = ptr;
	return (arg);
}

void	*car(void *arg)
{
	pthread_mutex_lock(&mutex_fuel);
	if (fuel >= 40)
	{
		fuel = fuel - 40;
		printf("Car got this fuel. Now left: %d\n", fuel);
	}
	else 
	{
		printf("Car got NO fuel. fuel left: %d\n", fuel);
	}
	pthread_mutex_unlock(&mutex_fuel);
	//sleep(1);
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