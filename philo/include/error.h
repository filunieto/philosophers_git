/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:34:37 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/05 14:22:59 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* ************************************************************************** */
/* COLORS																	..*/
/* ************************************************************************** */
# define YELLOW	"\033[1;33m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define GRAY	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RED	"\033[1;31m"
# define MAGENTA "\e[35m"
# define BLUEE  "\e[32m"
# define REDD  "\e[92m"
# define RESET  "\e[0m"


# define ERROR_ARG "number of arguments incorrect\n"
# define USAGE GREEN"Usage: ./philo <nbr_of_philosophers> <time\
_to_die> <time_to_eat> <time_to_sleep> [max meals]\n\
"CYAN"<nbr_of_philosophers>\tnumber of philosophers at the table\n\
<time_to_die>\t\tmaximum amount of time (in ms) a philosopher can spend\
 without eating\n\
<time_to_eat>\t\ttime (in ms) a philosopher needs to finish her meal\n\
<time_to_sleep>\t\ttime (in ms) a philosopher spends sleeping\n\
[max meals]\t\tnumber of times each philosopher must eat (optional \
parameter)"
# define OK "todo ok" //borrar

#endif