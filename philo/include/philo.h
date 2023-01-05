/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:46:04 by fnieves-          #+#    #+#             */
/*   Updated: 2023/01/05 21:16:12 by fnieves          ###   ########.fr       */
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
# include "error.h"

//philo/src/parser
int		print_error(char *error_mes, int usage);
void	free_err_exit(t_main_philo *philo);


int	parser_arg(int argc, char**argv, t_main_philo *philo);


//philo/tools/libft_tools
int		ft_strlen(const char *str);
int		atoi_phi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);


void	init_struct(t_main_philo *philo);
int		init_philo(t_main_philo *philo);


#endif