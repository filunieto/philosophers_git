/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:24:20 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 21:57:57 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	Run by a thread for each philosopher, simulating their actions
	in an infinite loop. The function takes a pointer to a t_philosop struct
	as an argument, which contains information about the philosopher such as
	their ID, status, and forks. The function first checks the philosopher's 
	status.If they are thinking, it calls the philo_eats() function to make them 
	acquire and eat with their forks. If they are sleeping, it calls 
	the print_time_msg() function to print a message indicating that the 
	philosopher is sleeping, 
	updates their status, and then calls the time_countdown() function to wait for
	a certain amount of time (the time it takes the philosopher to sleep) to pass.
	After the waiting, it calls the print_time_msg() function again to print a
	message indicating that the philosopher is now thinking and updates their 
	status. If the philosopher's status is DIEDS, it calls the philo_died() 
	function.
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
			time_countdown(philos, philos->philo->time_sleep);
			if (print_time_msg(philos, PHILO_THINKS) == 0)
				return (NULL);
			philos->status_phi = THINKS;
		}
		if (philos->status_phi == DIEDS)
			return (philo_died(philos));
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
			time_countdown(philos, philos->philo->time_sleep);
			if (print_time_msg(philos, BLUE "thinks") == 0)
				return (NULL);
			philos->status_phi = THINKS;
		}
		if (philos->status_phi == DIEDS)
			return (philo_died(philos));
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
			if (pthread_create(philo->philos[i].th, NULL,
					&infinite_simulation, (void *)&philo->philos[i]))
				return (print_error(ERR_INI_THR, 0));
		}
		else
		{
			if (pthread_create(philo->philos[i].th, NULL,
					&simulation_finite, (void *)&philo->philos[i]))
				return (print_error(ERR_INI_THR, 0));
		}
	}
	return (EXIT_SUCCESS);
}
