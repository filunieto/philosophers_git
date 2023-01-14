/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:45:49 by fnieves-          #+#    #+#             */
/*   Updated: 2023/01/14 21:27:22 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	join_philo(t_main_philo *philo)
{
	int		i;

	void *result;
	i = -1;
	while (++i < philo->numb_ph)
		pthread_join(*(philo->philos[i].th), &result);
	return (EXIT_SUCCESS);
}
