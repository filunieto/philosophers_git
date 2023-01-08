/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:11:13 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/07 23:08:32 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	struct timeval 
		time_t      tv_sec;      seconds 
		suseconds_t tv_usec;     microseconds 
	}
	La funcion imprimira el estado del filososfo (sleeps, thinks,..) 
	con su respectivo id.
	Si un threads llama a la función la bloqueará hasta que imprima, 
	y acto seguido se desbloqueará.
	Por qué 2 mutex LOCK? print and run?
*/


int	print_time_msg(t_philosop *philos, char *messg)
{
	int	running;
	int	new_diff;

	new_diff = gettimediff((struct timeval *)&philos->philo->start_dinner);
	pthread_mutex_lock(&philos->philo->mutex_print);
	pthread_mutex_lock(&philos->philo->mutex_run);
	running = philos->philo->running;
	if (running)
		printf(GRAY"%d %s \033[1;36m%3d  %s\n\033[1;37m", new_diff,
			"ms", philos.id, messg);
	pthread_mutex_unlock(&philos->philo->mutex_run);
	pthread_mutex_unlock(&philos->philo->mutex_print);
	return (running);
}

/*
	Devuelve la diferencia del instante dado con el
	instante actual
*/
int	gettimediff(struct timeval *t)
{
	struct timeval	*now;
	int				diff_time;
	//struct timeval	*time_diff;     usar esta variable para devolverla en lugar 
	gettimeofday(&now, NULL); //habría que asegurarla?
	diff_time = ((now->tv_sec - t->tv_sec) * 1000 + (now->tv_usec - t->tv_usec) / 1000);

	return (diff_time);
}

/*
	Devuelve la hora actual en ms
*/
long	get_actual_time(void)
{
	struct	timeval time_act;
	long	millsecond;
	
	gettimeofday(&time_act, NULL);
	millsecond = time_act.tv_sec * 1000;
	millsecond = millsecond +  time_act.tv_usec / 1000;
	return (millsecond);
}

/*
	Devuelve el status del philosofo?
*/
t_status_phi	time_countdown(t_philosop *philos, int time_count)
{
	long	start;
	long	now;
	long	time_2eat;

	start = get_actual_time();
	now = start;
	time_2eat = philos->start_eating.tv_sec * 1000  //Momento en el que nace el filososo. Puede que THinking or sleeping
		+ philos->start_eating.tv_usec / 1000;
	while (now < (start + time_count))
	{
		usleep(100);
		now = get_actual_time();
		if (time_2eat + philos->philo->time_die < now) //el momento en el que 
		{
			philos->status_phi = DIEDS;
			return (philos->status_phi);
		}
	}
	return (philos->status_phi);
}