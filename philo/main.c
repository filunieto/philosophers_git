/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:27:48 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/06 21:23:28 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
	cambiar la carpeta libft_tools por tools y anidar en src
	Philosop has finished eating, they put their forks back
	on the table and start sleeping. Once awake, they start 
	thinking again.
	int					time_die;
	int					time_eat;
	int					time_sleep;
	max time philos can think = time_die - time_sleep.
*/


void	init_struct(t_main_philo *philo)
{
	philo->numb_ph = 0;
	philo->time_die = 0;
	philo->time_eat = 0;
	philo->time_sleep = 0;
	philo->min_times_eat = 0;
	philo->loop = 0; // presuponemos que hay min numero de comida (no hay loop)
}

int	main(int argc, char**argv)
{
	t_main_philo	philo;

	init_struct(&philo);
	if (parser_arg(argc, argv, &philo))
		exit(EXIT_FAILURE);
	printf("valores en int de argumentos en main %i, %i, %i, %i.[%i] \n",philo.numb_ph, 
	philo.time_die, philo.time_eat, philo.time_sleep, philo.min_times_eat );
	if (init_philo(&philo))
		exit(EXIT_FAILURE);
	if (mutex_philo(&philo))
		exit(EXIT_FAILURE);
	if (create_philo(&philo))
		exit(EXIT_FAILURE);
	//write(1, OK, ft_strlen(OK));
	return (0);
}