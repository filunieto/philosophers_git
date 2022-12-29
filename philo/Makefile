# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 11:17:17 by fnieves           #+#    #+#              #
#    Updated: 2022/12/29 12:47:10 by fnieves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philo
CC 			= 	cc
FLAGS		=	-Wall -Wextra -Werror
FLAGS_PHILO	=	-pthread  -lpthread
RM			=	rm -f 

SRC			=	main.c					\
				src/parser/parser.c		\
				tools/libft_tools/ft_strlen.c


OBJ			=	${SRC:.c=.o}

$(NAME): $(OBJ)
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

all: $(NAME)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


# gcc -Wall -Wextra -Werror -pthread  -lpthread threads_main.c -o threads_main