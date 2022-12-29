/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:46:04 by fnieves-          #+#    #+#             */
/*   Updated: 2022/12/29 12:41:01 by fnieves          ###   ########.fr       */
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
void	print_error(void);

//philo/tools/libft_tools
int		ft_strlen(const char *str);


#endif