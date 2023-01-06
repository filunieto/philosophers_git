/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:58:30 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/06 20:35:33 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	print_error(char *error_mes, int usage)
{
	write (1, error_mes, ft_strlen(error_mes));
	if (usage)
		write (1, USAGE, ft_strlen(USAGE));
	return(EXIT_FAILURE);
}

int	free_err_exit(t_main_philo *philo)
{
	int i;

	i = 0;
	while (philo->philos[i].th)
	{
		free(philo->philos[i].th);
		philo->philos[i].th = NULL;
		i++;
	}
	free(philo->philos);
	philo->philos = NULL;
	return(print_error(ERR_MALLOC, 0)); //en este caso no haría falta poner a NULL ya que hacemos exit
}

// int	print_error2(char *error_mes)
// {
// 	write (1, error_mes, ft_strlen(error_mes));
// 	//write (1, USAGE, ft_strlen(USAGE));
// 	return(EXIT_FAILURE);
// }