/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:46:04 by fnieves-          #+#    #+#             */
/*   Updated: 2023/01/05 14:03:17 by fnieves          ###   ########.fr       */
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

# include "struct.h"
# include "error.h"

//philo/src/parser
int	print_error(char *error_mes);

//philo/tools/libft_tools
int		ft_strlen(const char *str);

void	init_struct(t_main *philo);


#endif