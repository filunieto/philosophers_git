/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:24:20 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/11 15:34:53 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	como funcion	print_time_msg
*/
void	*philo_died(t_philosop *philos)
{
	int	running;
	int	new_diff;

	new_diff = gettimediff((struct timeval *)&philos->philo->start_dinner);
	pthread_mutex_lock(&philos->philo->mutex_run);
	running = philos->philo->running;
	philos->philo->running = 0;
	pthread_mutex_unlock(&philos->philo->mutex_run);
		// printf(GRAY"%d %s \033[1;36m%3d  %s\n\033[1;37m", new_diff,
		// 	"ms", ph->id, RED"has died");
	if (running)
		printf(GRAY"%d ms	"CYAN7"%3d  "RED"%s\n", new_diff, philos->id, "has died");
	return (NULL);
}

/*
	Pasamos el parametro de la función arg
	Si el filosofo está pensando que  intente comer.
	EATS, 0
	SLEEPS, 1
	THINKS, 2
	DIEDS, 3
	NOSTATUS, 4
*/
void	*infinite_simulation(void *arg)
{
	t_philosop	*philos;

	philos = (t_philosop *)arg;
	//printf("Philosofer %i, estado %i \n", philos->id, philos->status_phi);
	while (1)
	{
		if (philos->status_phi == THINKS) //si está pensadno , que intente comer
			philo_eats(philos);
		if (philos->status_phi == SLEEPS)
		{
			if (print_time_msg(philos, PINK "sleeps") == 0)
				return (NULL);
			philos->status_phi = SLEEPS;//??
			//write(1,"1 cambia al estado sleeps en unfinit simulat?\n",46);
			time_countdown(philos, philos->philo->time_sleep);
			//write(1,"2 cambia al estado THINKS en unfinit simulat?\n",48);
			if (print_time_msg(philos, GRAY "thinks") == 0)
				return (NULL);
			//write(1,"3 cambia al estado THINKS en unfinit simulat?\n",48); //aqui parece que no llega
			philos->status_phi = THINKS;
		}
		if (philos->status_phi == DIEDS)
			return(philo_died(philos));
	}
	return (philos);
}

void	*simulation_finite(void *arg)
{
	t_philosop	*philos;

	philos = (t_philosop *)arg; //pasamos el argumento a la 
	while (philos->min_times_eat > 0)
	{
		if (philos->status_phi == THINKS)
			philo_eats(philos);
		if (philos->status_phi == SLEEPS && philos->min_times_eat > 0)
		{
			if (print_time_msg(philos, PINK "sleeps") == 0)
				return (NULL);
			philos->status_phi = SLEEPS;
			time_countdown(philos, philos->philo->time_sleep);
			if (print_time_msg(philos, BLUE "thinks") == 0)
				return (NULL);
			philos->status_phi = THINKS;
		}
		if (philos->status_phi == DIEDS)
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

	gettimeofday((struct timeval *)&philo->start_dinner, NULL); //comienza la simulacion y anotamos el instante
	i = -1;
	while (++i < philo->numb_ph)
	{
		if (philo->loop)
		{
			if (pthread_create(philo->philos[i].th, NULL, &infinite_simulation, (void *)&philo->philos[i])) //verificar lo sparametros
				return (print_error(ERR_INI_THR , 0));
		}
		else
		{
			if (pthread_create(philo->philos[i].th, NULL, &simulation_finite, (void *)&philo->philos[i]))
				return (print_error(ERR_INI_THR , 0));
		}
	}
	return (EXIT_SUCCESS);
}
