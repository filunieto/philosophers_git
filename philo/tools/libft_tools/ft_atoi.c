/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:46:01 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/05 15:43:32 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	ft_isspace(char c)
{
	return (c <= 32);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi2(const char *str)
{
	int nbr;
	int sign = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while(ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}


int	ft_atoi(const char *nptr) //ft_atoi_philo
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if ('+' == nptr[i] || '-' == nptr[i])
	{
		if ('-' == nptr[i])
			sign = -1;
		i++;
	}
	while (nptr[i] && res <= 2147483648)
	{
		if (!ft_isdigit(nptr[i]))
			return (-1);
		res = res * 10 + ((nptr[i++] - '0'));
	}
	if ((sign == -1 && res > 2147483648) || (sign == 1 && res > 2147483647))
		return (-1);
	return (sign * (res));
}
