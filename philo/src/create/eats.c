/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eats.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:44:35 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 21:54:47 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	The function fork_takeone() is used to acquire a fork by a philosopher.
	In argument 1: the philosopher i struct and the time at which 
	they started eating. 
	Argument 2: A pthread_mutex_t, which is used for synchronization to ensure
	that only one philosopher can acquire a fork at a time.
	The function starts by initializing a variable 'res' to 0 and then locks 
	the mutex using the pthread_mutex_lock() function.
	This prevents any other philosopher from accessing the fork at the same time.
	It then checks if the philosopher currently has a fork by checking the value 
	of the 'has_fork' variable in the t_philosop struct.
	If the value is 0, it means the philosopher does not have a fork, 
	and the function sets the 'has_fork' variable to 1 and sets the 'res' 
	variable to 1, indicating that the fork has been successfully acquired.
	If the philosopher already has a fork, the function proceeds to unlock
	the mutex using the pthread_mutex_unlock() function and returns 0,
	indicating that the fork could not be acquired.
	The function then returns the value of 'res', which is 1 if 
	the fork was successfully acquired, and 0 otherwise.
*/
int	fork_takeone(t_philosop *philos, pthread_mutex_t *mutx)
{
	int	res;

	res = 0;
	pthread_mutex_lock(mutx);
	if (philos->has_fork == 0)
	{
		philos->has_fork = 1;
		res = 1;
	}
	pthread_mutex_unlock(mutx);
	return (res);
}

/*
	This function is used to acquire left or right forks needed for a
	philosopher to eat. It converts to "time_eating" the instant at which
	the philosopher started eating in ms. It then enters in a while loop that 
	calls the fork_takeone() function to try and acquire a fork.
	This loop continues until fork_takeone() returns 1, indicating 
	that the fork has been successfully acquired.
	It then checks if the time at which the philosopher started eating 
	plus the time the philosopher can live before dying is less than the current
	time. If it is, it means the philosopher has died of starvation, and the
	function sets the philosopher's status to DIEDS and returns 0.
	If the philosopher was able to the forks, the function returns 1.
*/
int	philo_takefork(t_philosop *philos, pthread_mutex_t *mutx)
{
	long	time_eating;

	if (!philos || !mutx)
		return (0);
	time_eating = philos->start_eating.tv_sec * 1000
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

/*
	It uses the mutex to lock access to the fork 
	and sets the philosopher's has_fork variable to 0,
	indicating that they no longer have the fork.
*/
void	fork_release(t_philosop *philos, pthread_mutex_t *mutx)
{
	pthread_mutex_lock(mutx);
	philos->has_fork = 0;
	pthread_mutex_unlock(mutx);
}

/*
	This function is used to make the philosopher eat. 
	It first calls philo_takefork() to acquire the left and right forks.
	Then it prints messages indicating the philosopher has taken 
	the left and right forks and is now eating. It updates the philosopher's 
	status and the time at which they started eating. It then calls the 
	time_countdown() function, which waits for a certain amount of 
	time (the time it takes the philosopher to eat) to pass. After the waiting, 
	the philosopher releases the left and right forks, and updates the number 
	of times they have eaten.
	It also updates the time when the philosophers starts to eat
*/
void	philo_eats(t_philosop *philos)
{
	if (philo_takefork(philos, &philos->mutx_left_fork) == 0)
		return ;
	if (print_time_msg(philos, LEFT_FORK) == 0)
		return ;
	if (philo_takefork(philos->next, philos->mutx_right_fork) == 0)
		return ;
	if (print_time_msg(philos, RIGHT_FORK) == 0)
		return ;
	if (print_time_msg(philos, PHILO_EATS) == 0)
		return ;
	philos->status_phi = EATS;
	gettimeofday((struct timeval *)&philos->start_eating, NULL);
	if (time_countdown(philos, philos->philo->time_eat) == DIEDS)
		return ;
	fork_release(philos, &philos->mutx_left_fork);
	fork_release(philos->next, philos->mutx_right_fork);
	philos->min_times_eat--;
	philos->status_phi = SLEEPS;
}
