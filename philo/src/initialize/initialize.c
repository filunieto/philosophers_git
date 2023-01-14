/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:02:31 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 20:13:37 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
/*
	philo->loop = 0; we assume that there is min number of food (no loop)
	philo->running = 1; dinner is taking place
*/
void	init_struct(t_main_philo *philo)
{
	philo->numb_ph = 0;
	philo->time_die = 0;
	philo->time_eat = 0;
	philo->time_sleep = 0;
	philo->min_times_eat = 0;
	philo->loop = 0;
	philo->running = 1;
}

/*
	Creating philosophers:
	The even-numbered start thinking and ready to eat, and the 
	odd-numbered start sleeping. 
	They are assigned the main structure
	They start without a fork
	They are assigned the instant of the current time of their creation, 
	and we save it in philos->start_eating.
*/

void	new_philosop(int i, t_philosop *philos ,t_main_philo *philo)
{
	philos->id = i + 1;
	if (i % 2 == 0)
		philos->status_phi = THINKS;
	else 
		philos->status_phi = SLEEPS;
	philos->has_fork = 0;
	philos->philo = philo;
	philos->next = NULL;
	philos->min_times_eat = philo->min_times_eat;
	gettimeofday((struct timeval *)&philos->start_eating, NULL);
}

/*
	Create the array of pointers to the structure with the total number of philosophers.
	Reserve space for each thread and assign a new philosopher to it.
	After creating the philosophers, if we have more than 1,
	philo->philos[i].next = &philo->philos[(i + 1) % philo->numb_ph];
	we concatenate them in a circular list.
	At the end we also call the initialize mutex function.
*/
int	init_philo(t_main_philo *philo)
{
	int	i;

	i = -1;
	philo->philos = (t_philosop *)ft_calloc(philo->numb_ph, sizeof(t_philosop));
	if (!philo->philos)
		return(print_error(ERR_MALLOC, 0));
	while (++i < philo->numb_ph)
	{
		philo->philos[i].th = (pthread_t *)ft_calloc(1, sizeof(pthread_t));
		if (!philo->philos[i].th)
			free_err_exit(philo);
		new_philosop(i, &philo->philos[i], philo);
	}
	if (philo->numb_ph > 1)
	{
		i = -1;
		while (++i < philo->numb_ph)
			philo->philos[i].next = &philo->philos[(i + 1) % philo->numb_ph];
	}
	if (init_mutex_philo(philo))
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
	We initialize the mutex in each left tenedr. If in addition 
	there is more than one filosofo, we will match it to the right
	fork of the next thread. In addition, we initialize the mutex print 
	and run. In total we initialize 3 mutex: fork, print and run. 
*/
int	init_mutex_philo(t_main_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->numb_ph)
		if (pthread_mutex_init(&philo->philos[i].mutx_left_fork, NULL) != 0)
			return (print_error(ERR_INI_MUTX, 0));
	if (philo->numb_ph > 1)
	{
		i = -1;
		while (++i < philo->numb_ph)
			philo->philos[i].mutx_right_fork = &philo->philos[((i + 1) % philo->numb_ph)].mutx_left_fork;
	}
	if (pthread_mutex_init(&philo->mutex_print, NULL) != 0)
		return (print_error(ERR_INI_MUTX, 0));
	if (pthread_mutex_init(&philo->mutex_run, NULL) != 0)
		return (print_error(ERR_INI_MUTX, 0));
	return (EXIT_SUCCESS);
}
