/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:27:48 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/05 14:14:53 by fnieves          ###   ########.fr       */
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
*/
int parser_arg(int argc, char**argv, t_main *philo)
{
	if (argc > 6 || argc < 5)
		return(print_error(ERROR_ARG));
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