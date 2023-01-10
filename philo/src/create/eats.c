/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eats.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:44:35 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/08 23:58:42 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	
*/
int	philo_takeone(t_philosop *philos, pthread_mutex_t *mutx)
{
	int	res;

	res = 0;
	pthread_mutex_lock(mutx);
	if (philos->has_fork = 0)
	{
		philos->has_fork = 1;
		res = 1;
	}
	pthread_mutex_unlock(mutx);
	return (res);
}

/*
	
*/
int	philo_takefork(t_philosop *philos, pthread_mutex_t *mutx)
{
	long	time_eating;
	
	if (!philos || !mutx)
		return (0);
	time_eating = philos->start_eating.tv_sec * 1000  //Momento en el que comienza a comer el filososo, antes de que esta función sea llamada
		+ philos->start_eating.tv_usec / 1000;
	while (fork_takeone(philos, mutx) == 0)
	{
		if (time_eating + philos->philo->time_die < get_actual_time())
		{
			philos->status_phi = DIEDS;
			return (0);
		}	
	}
	return (1);
}

void	fork_release(t_philosop *philos, pthread_mutex_t *mutx)
{
	pthread_mutex_lock(mutx);
	philos->has_fork = 0;
	pthread_mutex_unlock(mutx);
}

/*
	El filososfo coge el tenedor izquierdo y se imprime el mensaje
	(desbloqueado y bloqueado previamente).
	Lo mismo con el tenedor derecho. Se imprime que está comiendo y 
	cambiamos el status y el instante en el que empieza a comer.
	Llamamos a la función time_countdown (Atención revisar esto)
*/
void	philo_eats(t_philosop *philos)
{
	if (philo_takefork(philos, &philos->mutx_left_fork) == 0)
		return ;
	if	(print_time_msg(philos, LEFT_FORK) == 0)
		return ;
	if (philo_takefork(philos->next, philos->mutx_right_fork) == 0)
		return ;
	if	(print_time_msg(philos, RIGHT_FORK) == 0)
		return ;
	if	(print_time_msg(philos, PHILO_EATS) == 0)
		return ;
	philos->status_phi = EATS;
	gettimeofday((struct timeval *)&philos->start_eating, NULL); //actualiza el instante  al  que empieza a comer
	if (time_countdown(philos, philos->philo->time_eat) == DIEDS)
		return ;
	fork_release(philos, &philos->mutx_left_fork);
	fork_release(philos->next, philos->mutx_right_fork);
	philos->min_times_eat--;
	philos->status_phi = SLEEPS;
}
