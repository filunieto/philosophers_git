/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:40:36 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 14:40:13 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*point;

	point = (unsigned char *)(s);
	i = 0;
	while (i < n)
	{
		point[i] = 0;
		i++;
	}
}

/*
	Returns a pointer of zeros of 'nmeb' element
	of size bytes.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}
