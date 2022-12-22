/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argum_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:47:50 by fnieves           #+#    #+#             */
/*   Updated: 2022/12/20 21:53:24 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int primes[10] = {2 , 3 , 5, 7 , 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	void *ptr = NULL;
	sleep(1);
	int index; //cambia la estrella de lugar
	index = *(int *)arg;
	//index = *arg;
	printf("%d ", primes[index]);
	return (ptr);
}

int main (void)
{
	pthread_t th[10];
	for (int i = 0; i < 10; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, &i) != 0)
			perror("Failed to create thread");

	}
	for (int i = 0; i < 10; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	return (0);
}
