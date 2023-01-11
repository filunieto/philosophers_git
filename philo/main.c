/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:27:48 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/11 16:35:46 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"



/*
	Cambiar las frases:  has taken a fork 
	cambiar la carpeta libft_tools por tools y anidar en src.
	Philosop has finished eating, they put their forks back
	on the table and start sleeping. Once awake, they start 
	thinking again.
	int					time_die;
	int					time_eat;
	int					time_sleep;
	max time philos can think = time_die - time_sleep.
*/

int	main(int argc, char**argv)
{
	t_main_philo	philo;

	init_struct(&philo);
	if (parser_arg(argc, argv, &philo))
		exit(EXIT_FAILURE);
	if (init_philo(&philo))
		exit(EXIT_FAILURE);
	if (mutex_philo(&philo))
		exit(EXIT_FAILURE);
	if (create_philo(&philo)) //podemos llamarrlo start dinner?
		exit(EXIT_FAILURE);
	if (join_philo(&philo))
		exit(EXIT_FAILURE);
	//write(1, OK, ft_strlen(OK));
	return (0);
}