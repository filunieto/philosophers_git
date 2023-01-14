/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_phi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:46:01 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 22:06:40 by fnieves-         ###   ########.fr       */
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

int	atoi_phi(const char *nptr)
{
	int				i;
	unsigned int	res;
	int				sign;

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
	while (nptr[i] != 0 && res <= 2147483648)
	{
		if (!ft_isdigit(nptr[i]))
			return (-1);
		res = res * 10 + ((nptr[i++] - '0'));
	}
	if ((sign == -1 && res > 2147483648) || (sign == 1 && res > 2147483647))
		return (-1);
	return ((int)(sign * res));
}
