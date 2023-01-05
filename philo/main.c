/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:27:48 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/05 17:37:13 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	init_struct(t_main *philo)
{
	philo->min_times_eat = 0;
	philo->time_die = 0;
}

/*
	La función analiza los argumentos de ntrada
	Si alguno no cuadra, devuelve un valor distinto de 0
	Qué ocurre si tenemos valores de 0?
*/
int parser_arg(int argc, char**argv, t_main *philo)
{
	if (argc > 6 || argc < 5)
		return(print_error(ERROR_ARG));
	if (ft_atoi(argv[1]) < 0)
		return(print_error(NUM_PHILO));
	philo->numb_ph = ft_atoi(argv[1]);
	if (!philo->numb_ph)
		return(print_error(NUM_PHILO_POS));
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return(print_error(ERR_ARG_TIME));
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if (philo->time_die < 0 || philo->time_eat < 0 || philo->time_sleep < 0)
		return(print_error(ERR_ARG_TIME));
	//printf("valores en int de argumentos %i, %i, %i, %i. \n",philo->numb_ph, philo->time_die, philo->time_eat, philo->time_sleep );
	return (0);
}

int	main(int argc, char**argv)
{
	t_main	philo;

	init_struct(&philo);
	if (parser_arg(argc, argv, &philo))
		exit(EXIT_FAILURE);
	write(1, OK, ft_strlen(OK));
	return (0);
}