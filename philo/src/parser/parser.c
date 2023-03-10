/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:08:25 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 21:58:43 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	parser_arg(int argc, char**argv, t_main_philo *philo)
{
	if (argc > 6 || argc < 5)
		return (print_error(ERROR_ARG, 1));
	if (atoi_phi(argv[1]) < 0)
		return (print_error(ERR_NUM_PHILO, 1));
	philo->numb_ph = atoi_phi(argv[1]);
	if (!philo->numb_ph || philo->numb_ph > MAX_PHILO)
		return (print_error(ERR_NUM_PHILO2, 1));
	if (atoi_phi(argv[2]) < 0 || atoi_phi(argv[3]) < 0 || atoi_phi(argv[4]) < 0)
		return (print_error(ERR_ARG_TIME, 1));
	philo->time_die = atoi_phi(argv[2]);
	philo->time_eat = atoi_phi(argv[3]);
	philo->time_sleep = atoi_phi(argv[4]);
	if (philo->time_die < 0 || philo->time_eat < 0 || philo->time_sleep < 0)
		return (print_error(ERR_ARG_TIME, 1));
	if (argc == 6)
	{
		if (atoi_phi(argv[5]) < 0)
			return (print_error(ERR_ARG_TIME, 1));
		philo->min_times_eat = atoi_phi(argv[5]);
	}
	else
		philo->loop = 1;
	return (EXIT_SUCCESS);
}
