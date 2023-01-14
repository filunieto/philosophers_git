/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:34:37 by fnieves           #+#    #+#             */
/*   Updated: 2023/01/14 14:51:59 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/* ************************************************************************** */
/* COLORS																	..*/
/* ************************************************************************** */
# define YELLOW	"\033[1;33m"
# define GREEN	"\033[1;32m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define GRAY	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define CYAN7	"\033[1;37m"
# define RED	"\033[1;31m"
# define MAGENTA "\e[35m"
# define BLUEE  "\e[32m"
# define REDD  "\e[92m"
# define RESET  "\e[0m"


# define ERROR_ARG RED"number of arguments incorrect\n"

# define ERR_NUM_PHILO RED"number of philosophers incorrect. At least 1 \
philosopher required\n"
# define ERR_NUM_PHILO_2 RED"Please at least 1 \
philosopher required and maximum 200\n"
# define ERR_ARG_TIME RED"Time format not correct: \
in [ms] and not less than 0\n"
# define ERR_MALLOC RED"Error: malloc not correct\n"
# define ERR_MALLOC_TH RED"Error: malloc of threads not correct\n"
# define ERR_INI_MUTX RED"Error: Failed to initialize mutex\n"
# define ERR_INI_THR RED"Error: Failed to create pthread\n"


# define USAGE GREEN"Usage: ./philo <nbr_of_philosophers> <time\
_to_die> <time_to_eat> <time_to_sleep> [min meals]\n\
"CYAN"<nbr_of_philosophers>\tnumber of philosophers at the table\n\
<time_to_die>\t\tmaximum  time [ms] a philosopher can spend\
 without eating\n\
<time_to_eat>\t\ttime [ms] a philosopher needs to finish her meal\n\
<time_to_sleep>\t\ttime [ms] a philosopher spends sleeping\n\
[min meals]\t\tminimal number of times each philosopher must eat (optional \
parameter), otherwise simulation stops when a philosopher dies.\n\
"RESET"Example: ./philo 2 120 20 20 2\n\
Example: ./philo 2 800 200 300\n\
Example: ./philo 4 400 200 200"

# define LEFT_FORK YELLOW"has taken a fork"RESET"" //igual no es necesario el slash n
# define RIGHT_FORK CYAN"has taken a fork"RESET""
# define PHILO_EATS GREEN"is eating"RESET""
# define PHILO_SLEEPS PINK"is sleeping"RESET""
# define PHILO_THINKS CYAN7"is thinking"RESET""
# define PHILO_DIED RED"died"RESET""
#endif