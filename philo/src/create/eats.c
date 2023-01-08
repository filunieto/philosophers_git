/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eats.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:44:35 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/08 17:19:23 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


/*
	El filososfo cohe el tenedor izquierdo y se imprime el mensaje
	(desbloqueado y bloqueado previamente).
	Lo mismo con el tenedor derecho. Se imprime que está comiendo y 
	cambiamos el status y el instante en el que empieza a comer.
	Llamamos a la función time_countdown (Atención revisar esto)
	
	
*/
void	philo_eats(t_philosop *philos)
{
	if (philo_takefork(philos, &philos->mutx_left_fork) == 0)
		return ;
	if	(print_time_msg(philos, LEFT_FORK) == 0)
		return ;
	if (philo_takefork(philos->next, philos->mutx_right_fork) == 0)
		return ;
	if	(print_time_msg(philos, RIGHT_FORK) == 0)
		return ;
	if	(print_time_msg(philos, PHILO_EATS) == 0)
		return ;
	philos->status_phi = EATS;
	gettimeofday((struct timeval *)&philos->start_eating, NULL);
	if (time_countdown(philos, philos->philo->time_eat) == DIEDS)
		return ;
	fork_release(&philos->mutx_left_fork, philos);
	fork_release(philos->mutx_right_fork, philos->next);
	philos->min_times_eat--;
	philos->status_phi = SLEEPS;
	
}