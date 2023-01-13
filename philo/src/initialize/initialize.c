/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:02:31 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/13 13:48:54 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	init_struct(t_main_philo *philo)
{
	philo->numb_ph = 0;
	philo->time_die = 0;
	philo->time_eat = 0;
	philo->time_sleep = 0;
	philo->min_times_eat = 0;
	philo->loop = 0; // presuponemos que hay min numero de comida (no hay loop)
	philo->running = 1; //la cena está teniendo lugar
}

/*
	Creando filosofos:
	Los pares comienzan pensando y listos para comer, y los 
	impares durmiendo.
	Se les asigna la estructura prnicpal
	Cominezan sin tenedor
	Se les asigna, el instante de la hora actual
*/

void	new_philosop(int i, t_philosop *philos ,t_main_philo *philo)
{
	philos->id = i + 1; //desde 1 hasta nb_philo 
	if (i % 2 == 0) //es philosofo par
		philos->status_phi = THINKS;
	else 
		philos->status_phi = SLEEPS;
	philos->has_fork = 0;
	philos->philo = philo; //la estructura del filosofo apunta a la estructura main
	philos->next = NULL;
	philos->min_times_eat = philo->min_times_eat;
	gettimeofday((struct timeval *)&philos->start_eating, NULL); //nos da la hora en ms .Momento en el que nace el filososo
	//la estructura de arriba podría ser long en lugar de (struct timeval *)??
	//write(1, "despues de gettime\n", 30);
}

/*
	Creamos el array a punteros a la estrcutura con el numero de philosofos total
	Malloquemos cada  thread y le asignamos un nuevo filosofo
	Desues de crear los filosofos 
	philo->philos[i].next = &philo->philos[(i + 1) % philo->numb_ph];
	los encadenamos en una lista cerrada
*/
int	init_philo(t_main_philo *philo)
{
	int	i;

	i = -1;
	philo->philos = (t_philosop *)malloc(sizeof(t_philosop) * philo->numb_ph); //array de punteros  a philosophers.
	//philo->philos = (t_philosop *)ft_calloc(sizeof(t_philosop), philo->numb_ph); //sería esta la manera correcta de llamar a calloc
	if (!philo->philos)
		return(print_error(ERR_MALLOC, 0));
	while (++i < philo->numb_ph)
	{
		//write(1, "en while\n", 10);	
		philo->philos[i].th = (pthread_t *)malloc(sizeof(pthread_t)); //usar calloc como arriba?
		if (!philo->philos[i].th)
			free_err_exit(philo); //hay que liberar cada philo[i].th y despues la estruct completa. mejor usar calloc previamente?
		new_philosop(i, &philo->philos[i], philo);
	}
	if (philo->numb_ph > 1)
	{
		i = -1;
		while (++i < philo->numb_ph)
			philo->philos[i].next = &philo->philos[(i + 1) % philo->numb_ph]; //lista circular 
	}
	//write(1, "despues de init philo\n", 24);
	return (EXIT_SUCCESS);
}

/*
	Inicializmos el mutex en cada tenedr izquierdo. Si además hay más de un filosofo,
	lo igualaremos al tenedor derecho del siguiente filosofo.
	Aparte inicializamos el mutex  print y run
	En total inicializmos  3 Mutex: tenedor, print y run 
*/

int	mutex_philo(t_main_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->numb_ph)
	{
		//write(1, "en while mutex\n", 24);
		if (pthread_mutex_init(&philo->philos[i].mutx_left_fork, NULL) != 0)
			return (print_error(ERR_INI_MUTX, 0));
	}
	if (philo->numb_ph > 1) //si hay más de un filosofo igualamaos el fork izquierdo  de filososofo i , con el fork derecho de filsoofo i +1
	{
		i = -1;
		while (++i < philo->numb_ph) //hay que poner el adress & below?
			philo->philos[i].mutx_right_fork = &philo->philos[((i + 1) % philo->numb_ph)].mutx_left_fork;
	}
	if (pthread_mutex_init(&philo->mutex_print, NULL) != 0)
		return (print_error(ERR_INI_MUTX, 0));
	if (pthread_mutex_init(&philo->mutex_run, NULL) != 0)
		return (print_error(ERR_INI_MUTX, 0));
	return (EXIT_SUCCESS);
}
