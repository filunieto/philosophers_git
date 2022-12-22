/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_using_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:47:50 by fnieves           #+#    #+#             */
/*   Updated: 2022/12/21 00:26:42 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int primes[10] = {2 , 3 , 5, 7 , 11, 13, 17, 19, 23, 29};

// atexit(check_leaks)
void check_leaks()
{
	system("leaks 1_using_threads");
}

void	*routine(void *arg)
{
	//void *ptr = NULL;
	int index; //cambia la estrella de lugar
	index = *(int *)arg;
	int sum = 0;
	for (int j = 0; j < 5; j++)
		sum += primes[index + j];
	//printf("%d ", primes[index]);
	printf("Local sum %d \n", sum);

	//free(arg);
	*(int *)arg = sum;
	return (arg);
	//return (ptr);
}

int main (void)
{
	pthread_t th[2];
	int i;
	int *a;
	int *res;
	int globalsum = 0;
	for (i = 0; i < 2; i++)
	{
		a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("Failed to create thread");
	}
	for (i = 0; i < 2; i++)
	{
		if (pthread_join(th[i], (void**)&res) != 0)
			perror("Failed to join thread");
		globalsum += *res;
		free (res);
	}
	//leaks;
	atexit(check_leaks);
	printf("Global sum: %d\n", globalsum);
	return (0);
}
