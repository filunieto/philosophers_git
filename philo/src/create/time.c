/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:11:13 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 21:40:57 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


/*
	The function is used to print a message indicating the time, philosopher id
	and status that user sees.
	It starts by calling the gettimediff() function to calculate the
	time difference between the current time and the start of dinner.
	It then locks two mutexes, one for printing and one for running.
	It stores the value of the running variable in the t_philos struct in a local variable 'running'.
	It then checks if the running variable is true, if so it prints the message status
	with the time and philosopher id that user sees.
	It then unlocks the mutexes and returns the value of the running variable.
	If in the middel of the function dinner stops , it will return 0, and will not print
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
		printf(GRAY"%d "BLUE"%d %s\n", new_diff, philos->id, messg);
	pthread_mutex_unlock(&philos->philo->mutex_run);
	pthread_mutex_unlock(&philos->philo->mutex_print);
	return (running);
}

/*
	Same as print_time_msg(), but it does not lock the print function
	and will set variable running to 0
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
	if (running)
		printf(GRAY"%d "BLUE"%d %s\n", new_diff, philos->id, PHILO_DIED);
	return (NULL);
}

/*
	Used to calculate the time difference between the current time 
	and the time passed as an argument.
*/
int	gettimediff(struct timeval *t)
{
	struct timeval	now;
	int				diff_time;

	gettimeofday(&now, NULL);
	diff_time = ((now.tv_sec - t->tv_sec) * 1000 + (now.tv_usec - t->tv_usec) / 1000);
	return (diff_time);
}

/*
	Return current time in milliseconds.
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
	Is used to wait for a certain amount of time (the time it takes the philosopher to eat)
	to pass. Will change the status to DIED if time to died is consummed since start eating
	It starts by calling the get_actual_time() function to get the current
	time and stores it in a variable 'start'. It also gets the time at which the philosopher
	started eating and stores it in a variable 'started_eating'.
	It then enters a while loop that continues until the current time is greater
	than the start time plus the time it takes the philosopher to eat.
	Inside the while loop it calls the usleep(100) function to sleep for 100 microseconds and then updates
*/
t_status_phi	time_countdown(t_philosop *philos, int time_count)
{
	long	start;
	long	now;
	long	started_eating;

	start = get_actual_time();
	now = start;
	started_eating = philos->start_eating.tv_sec * 1000
		+ philos->start_eating.tv_usec / 1000;
	while (now < (start + time_count))
	{
		usleep(100);
		now = get_actual_time();
		if (started_eating + philos->philo->time_die < now)
		{
			philos->status_phi = DIEDS;
			return (philos->status_phi);
		}
	}
	return (philos->status_phi);
}
