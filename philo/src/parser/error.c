/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:58:30 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/05 14:58:44 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	print_error(char *error_mes)
{
	write (1, error_mes, ft_strlen(error_mes));
	write (1, USAGE, ft_strlen(USAGE));
	return(EXIT_FAILURE);
}