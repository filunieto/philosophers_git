/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:27:48 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 21:43:00 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
	atexit(check_leaks);
*/
void	check_leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char**argv)
{
	t_main_philo	philo;

	init_struct(&philo);
	if (parser_arg(argc, argv, &philo))
		exit(EXIT_FAILURE);
	if (init_philo(&philo))
		exit(EXIT_FAILURE);
	if (lets_start_dinning(&philo))
		exit(EXIT_FAILURE);
	if (join_philo(&philo))
		exit(EXIT_FAILURE);
	free_philo(&philo);
	return (0);
}
