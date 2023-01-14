/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:46:04 by fnieves-          #+#    #+#             */
/*   Updated: 2023/01/14 21:28:04 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#define MAX_PHILO 200
/*
	Tenemos una etructura que apunta a otra estructura y así sucesivamente
	porque solo podemos pasar un parametro a las funciones de los threads.
	Y esta es la manera de que dichas funciones accedan a toda la información
*/

typedef enum e_status_phi
{
	EATS,  //0
	SLEEPS, //1
	THINKS, //2
	DIEDS, //3
	NOSTATUS,
}t_status_phi;

typedef struct s_philosop
{
	int						id;
	t_status_phi			status_phi;
	pthread_t				*th;
	pthread_mutex_t			mutx_left_fork;
	pthread_mutex_t			*mutx_right_fork;
	int						has_fork;
	int						min_times_eat;
	const struct timeval	start_eating;
	struct s_philosop		*next;
	struct s_main_philo		*philo;
}	t_philosop;

/*
	running: we set it to 1 , to know that the phyllosophs are having dinner.
	0 when the dinner is over (either by death or because it 
	has eaten the min number of times).
*/
typedef struct s_main_philo
{
	int						numb_ph;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						min_times_eat;
	int						loop;
	t_philosop				*philos;
	pthread_mutex_t			mutex_run;
	pthread_mutex_t			mutex_print;
	const struct timeval	start_dinner;
	int						running;
}		t_main_philo;

#endif