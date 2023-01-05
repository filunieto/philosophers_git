/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:27:48 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/05 21:32:53 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
	cambiar la carpeta libft_tools por tools y anidar en src
	Philosop has finished eating, they put their forks back
	on the table and start sleeping. Once awake, they start 
	thinking again.
	int					time_die;
	int					time_eat;
	int					time_sleep;
	max time philos can think = time_die - time_sleep.
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
	gettimeofday((struct timeval *)&philos->start_eating, NULL); //nos da la hora en ms
}

void	init_struct(t_main_philo *philo)
{
	philo->numb_ph = 0;
	philo->time_die = 0;
	philo->time_eat = 0;
	philo->time_sleep = 0;
	philo->min_times_eat = 0;
	philo->loop = 0; // presuponemos que hay min numero de comida (no hay loop)
}

int	init_philo(t_main_philo *philo)
{
	int	i;

	i = -1;
	philo->philos = (t_philosop *)malloc(sizeof(t_philosop) * philo->numb_ph); //array de punteros  a philosophers.
	//philo->philos = (t_philosop *)ft_calloc(sizeof(t_philosop), philo->numb_ph); //sería esta la manera correcta de llamar a calloc
	if (!philo->philos)
		print_error(ERR_MALLOC, 0);
	while (++i < philo->numb_ph)
	{
		philo->philos[i].th = (pthread_t *)malloc(sizeof(pthread_t)); //usar calloc como arriba?
		if (!philo->philos[i].th)
			free_err_exit(philo); //hay que liberar cada philo[i].th y despues la estruct completa. mejor usar calloc previamente?
		new_philosop(i, &philo->philos[i], philo);
	}
	return (EXIT_SUCCESS);
}


int	main(int argc, char**argv)
{
	t_main_philo	philo;

	init_struct(&philo);
	if (parser_arg(argc, argv, &philo))
		exit(EXIT_FAILURE);
	printf("valores en int de argumentos en main %i, %i, %i, %i.[%i] \n",philo.numb_ph, 
	philo.time_die, philo.time_eat, philo.time_sleep, philo.min_times_eat );
	if (init_philo(&philo))
		exit(EXIT_FAILURE);
	//write(1, OK, ft_strlen(OK));
	return (0);
}