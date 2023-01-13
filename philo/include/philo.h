/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:46:04 by fnieves-          #+#    #+#             */
/*   Updated: 2023/01/13 13:47:10 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>
# include <time.h>

# include "struct.h"
# include "messages.h" 

//philo/src/parser
int		print_error(char *error_mes, int usage);
int		free_err_exit(t_main_philo *philo);
int		parser_arg(int argc, char**argv, t_main_philo *philo);
void	free_main_str(t_main_philo *philo);


//philo/tools/libft_tools
int		ft_strlen(const char *str);
int		atoi_phi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);

//philo/src/initialize
void	init_struct(t_main_philo *philo);
int		init_philo(t_main_philo *philo);
int		mutex_philo(t_main_philo *philo);
void	free_philo(t_main_philo *philo);


//philo/src/create
int				create_philo(t_main_philo *philo);
void			*infinite_simulation(void *arg);
void			*simulation_finite(void *arg);
int				print_time_msg(t_philosop *philos, char *messg);
int				gettimediff(struct timeval *t);
long			get_actual_time(void);
t_status_phi	time_countdown(t_philosop *philos, int time_count);
int				philo_takefork(t_philosop *philos, pthread_mutex_t *mutx);
int				philo_takeone(t_philosop *philos, pthread_mutex_t *mutx);
void			fork_release(t_philosop *philos, pthread_mutex_t *mutx);
int				fork_takeone(t_philosop *philos, pthread_mutex_t *mutx);
void			philo_eats(t_philosop *philos);
int				join_philo(t_main_philo *philo);


void	check_leaks(void);






#endif