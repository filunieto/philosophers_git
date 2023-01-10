/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:24:20 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/10 19:48:16 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	como funcion	print_time_msg
*/
void	*philo_died(t_philosop *philos)
{
	int	running;
	int	new_diff;

	new_diff = gettimediff((struct timeval *)&philos->philo->start_dinner);
	pthread_mutex_lock(&philos->philo->mutex_run);
	running = philos->philo->running;
	philos->philo->running = 0;
	pthread_mutex_unlock(&philos->philo->mutex_run);
		// printf(GRAY"%d %s \033[1;36m%3d  %s\n\033[1;37m", new_diff,
		// 	"ms", ph->id, RED"has died");
	if (running)
		printf(GRAY"%d ms	"CYAN7"%3d  "RED"%s\n"CYAN"", new_diff, philos->id, "has died");
	return (NULL);
}

/*
	Pasamos el parametro de la función arg
	
*/
void	*simulation_loop(void *arg)
{
	t_philosop	*philos;

	philos = (t_philosop *)arg;
	while (1)
	{
		if (philos->status_phi == THINKS) //si está pensadno , que intente comer
			philo_eats(philos);
		if (philos->status_phi == SLEEPS)
		{
			if (print_time_msg(philos, PINK "sleeps") == 0)
				return (NULL);
			philos->status_phi = SLEEPS;//??
			time_countdown(philos, philos->philo->time_sleep);
			if (print_time_msg(philos, BLUE "thinks") == 0)
				return (NULL);
			philos->status_phi = THINKS;
		}
		if (philos->status_phi == DIEDS)
			return(philo_died(philos));
	}
	return (philos);
}

void	*simulation_noloop(void *arg)
{
	t_philosop	*philos;

	philos = (t_philosop *)arg; //pasamos el argumento a la 
	while (1)
	{
		if (philos->status_phi == THINKS)
			philo_eats(philos);
		if (philos->status_phi == SLEEPS)
		{
			if (print_time_msg(philos, PINK "sleeps") == 0)
				return (NULL);
			philos->status_phi = SLEEPS;
			time_countdown(philos, philos->philo->time_sleep);
			if (print_time_msg(philos, BLUE "thinks") == 0)
				return (NULL);
			philos->status_phi = THINKS;
		}
		if (philos->status_phi == DIEDS)
			return(philo_died(philos));
	}
	return (philos);
}

/*
	Asignamos el inicio de la simulacion a la estructura prinicpal.
	Diferenciamos 2 casos. Si el usuario ha especificado 
	el numero minimo de comidas (no_loop), loop en caso contrario.
*/

int	create_philo(t_main_philo *philo)
{
	int		i;

	gettimeofday((struct timeval *)&philo->start_dinner, NULL); //comienza la simulacion
	i = -1;
	while (++i < philo->numb_ph)
	{
		if (philo->loop)
		{
			if (pthread_create(philo->philos[i].th, NULL, &simulation_loop, (void *)&philo->philos[i])) //verificar lo sparametros
				return (print_error(ERR_INI_THR , 0));
		}
		else
		{
			if (pthread_create(philo->philos[i].th, NULL, &simulation_noloop, (void *)&philo->philos[i]))
				return (print_error(ERR_INI_THR , 0));
		}
	}
	return (EXIT_SUCCESS);
}
