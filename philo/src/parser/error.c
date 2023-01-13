/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:58:30 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/13 13:59:00 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	print_error(char *error_mes, int usage)
{
	write (1, error_mes, ft_strlen(error_mes));
	if (usage)
		write (1, USAGE, ft_strlen(USAGE));
	return(EXIT_FAILURE);
}

void free_main_str(t_main_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->numb_ph)
	{
		free(philo->philos[i].th);
		//philo->philos[i].th = NULL;
		i++;
	}
	free(philo->philos);
	//philo->philos = NULL;	
}

/*
	verificar esta funcion . Los th no se liberalizan así. Solo con join
*/
int	free_err_exit(t_main_philo *philo)
{
	int i;

	i = 0;
	while (philo->philos[i].th)
	{
		free(philo->philos[i].th);
		philo->philos[i].th = NULL;
		i++;
	}
	free(philo->philos);
	philo->philos = NULL;
	return(print_error(ERR_MALLOC, 0)); //en este caso no haría falta poner a NULL ya que hacemos exit
}

void	free_philo(t_main_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->numb_ph)
		pthread_mutex_destroy(&philo->philos[i].mutx_left_fork);
	pthread_mutex_destroy(&philo->mutex_print);
	pthread_mutex_destroy(&philo->mutex_run);
	i = -1;
	while (++i < philo->numb_ph)
		free(philo->philos[i].th);
	free(philo->philos);
}