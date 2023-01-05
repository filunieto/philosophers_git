/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:46:04 by fnieves-          #+#    #+#             */
/*   Updated: 2023/01/05 21:18:45 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef enum e_status_phi //pasarlo a #define
{
	EATS,
	SLEEPS,
	THINKS,
	DIEDS,
	NOSTATUS,
}t_status_phi;

typedef struct s_philosop
{
	int						id;
	t_status_phi			status_phi;
	pthread_t				*th;
	pthread_mutex_t			mutx_left_fork;
	pthread_mutex_t			mutx_right_fork;
	int						has_fork;
	int						min_times_eat;
	const struct timeval	start_eating;
	struct s_philosop		*next;
	struct s_main_philo		*philo;

	
}	t_philosop;


typedef struct s_main_philo
{
	int					numb_ph;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					min_times_eat;
	int					loop; //1 si no tenemos parametro, minimo No comidas
	t_philosop			*philos;
}		t_main_philo;


#endif