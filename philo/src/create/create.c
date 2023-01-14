/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:24:20 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 21:23:13 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


/*
	Seguimos despues de comer aqui
	Pasamos el parametro de la función arg
	En un bucle infinito: 
	Si el filosofo está pensando que  intente comer.
	EATS, 0
	SLEEPS, 1
	THINKS, 2
	DIEDS, 3
	NOSTATUS, 4
*/
void	*infinite_simulation(void *arg)
{
	t_philosop	*philos;

	philos = (t_philosop *)arg;
	while (1)
	{
		if (philos->status_phi == THINKS)
			philo_eats(philos);
		if (philos->status_phi == SLEEPS)
		{
			if (print_time_msg(philos, PHILO_SLEEPS) == 0)
				return (NULL);
			philos->status_phi = SLEEPS;
			time_countdown(philos, philos->philo->time_sleep);
			if (print_time_msg(philos, PHILO_THINKS) == 0)
				return (NULL);
			philos->status_phi = THINKS;
		}
		if (philos->status_phi == DIEDS)
			return(philo_died(philos));
	}
	return (philos);
}

void	*simulation_finite(void *arg)
{
	t_philosop	*philos;

	philos = (t_philosop *)arg;
	while (philos->min_times_eat > 0)
	{
		if (philos->status_phi == THINKS)
			philo_eats(philos);
		if (philos->status_phi == SLEEPS && philos->min_times_eat > 0)
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
	We assign the start of the simulation to the main structure 
	(before at inizialitaion) we assigned the time of creation for each philosopher.
	We differentiate 2 cases. If the user has specified the minimum
	number of meals (simulation_finite), otherwise "infinite_simulation".
	We will create the thread and will pass the structure and the function needed
*/

int	lets_start_dinning(t_main_philo *philo)
{
	int		i;

	gettimeofday((struct timeval *)&philo->start_dinner, NULL);
	i = -1;
	while (++i < philo->numb_ph)
	{
		if (philo->loop)
		{
			if (pthread_create(philo->philos[i].th, NULL, &infinite_simulation, (void *)&philo->philos[i]))
				return (print_error(ERR_INI_THR , 0));
		}
		else
		{
			if (pthread_create(philo->philos[i].th, NULL, &simulation_finite, (void *)&philo->philos[i]))
				return (print_error(ERR_INI_THR , 0));
		}
	}
	return (EXIT_SUCCESS);
}
