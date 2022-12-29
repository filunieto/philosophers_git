/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_vault.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:19:28 by fnieves-          #+#    #+#             */
/*   Updated: 2022/12/16 19:02:34 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void	*routine()
{
	void *ptr;
	printf("Test from threads1\n");
	sleep(3);
	printf("END from threads1\n");
	return (ptr);
}


void	*routine2()
{
	void *ptr;
	printf("Test from threads2\n");
	sleep(3);
	printf("END from threads2\n");
	return (ptr);
}


int	main(int argc, char	**argv)
{
	pthread_t	t1, t2;
	pthread_create(&t1, NULL, &routine, NULL);
	
	pthread_create(&t2, NULL, &routine2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
