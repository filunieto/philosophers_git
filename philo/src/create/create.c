/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:24:20 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/08 15:15:52 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	Pasamos el parametro de la función
*/
void	*simulation_loop(void *arg)
{
	t_philosop	*philos;

	philos = (t_philosop *)arg;
	while (1)
	{
		if (philos->status_phi = THINKS) //si está pensadno , que intente comer
			philo_eats(philos);
		if (philos->status_phi = SLEEPS)
		{
			if (print_time_msg(philos, PINK "sleeps") == 0)
				return (NULL);
			philos->status_phi = SLEEPS;
			time_countdown(philos, philos->philo->time_sleep);
			if (print_time_msg(philos, BLUE "thinks") == 0)
				return (NULL);
			philos->status_phi = THINKS;
		}
		if (philos->status_phi = DIEDS)
			return(philo_died(philos));
	}
	return (philos);
}

void	*simulation_noloop(void *arg)
{
	t_philosop	*philos;

	philos = (t_philosop *)arg;
	while (1)
	{
		if (philos->status_phi = THINKS)
			philo_eats(philos);
		if (philos->status_phi = SLEEPS)
		{
			if (print_time_msg(philos, PINK "sleeps") == 0)
				return (NULL);
			philos->status_phi = SLEEPS;
			time_countdown(philos, philos->philo->time_sleep);
			if (print_time_msg(philos, BLUE "thinks") == 0)
				return (NULL);
			philos->status_phi = THINKS;
		}
		if (philos->status_phi = DIEDS)
			return(philo_died(philos));
	}
	return (philos);
}

/*
	Asignamos el inicio de la simulacion a la estructura prinicpal.
	Diferenciamos 2 casos. Si el usuario ha especificado 
	el numero minimo de comidas (no_loop), loop en caso contrario.
*/

int	create_philo(t_main_philo *philo)
{
	int		i;

	gettimeofday((struct timeval *)&philo->start_dinner, NULL); //comienza la simulacion
	i = -1;
	while (++i < philo->numb_ph)
	{
		if (philo->loop)
		{
			if (pthread_create(philo->philos[i].th, NULL, &simulation_loop, (void *)&philo->philos[i])) //verificar lo sparametros
				return (print_error(ERR_INI_THR , 0));
		}
		else
		{
			if (pthread_create(philo->philos[i].th, NULL, &simulation_noloop, (void *)&philo->philos[i]))
				return (print_error(ERR_INI_THR , 0));
		}
	}
	return (EXIT_SUCCESS);
}
