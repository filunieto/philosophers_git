/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:27:48 by fnieves           #+#    #+#             */
/*   Updated: 2022/12/29 12:33:13 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char**argv)
{
	if (argc > 6 || argc < 5)
	{
		print_error();
	}
	return (0);
}