# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 11:17:17 by fnieves           #+#    #+#              #
#    Updated: 2023/01/05 14:48:21 by fnieves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC 			=	cc
FLAGS		=	-Wall -Wextra -Werror
FLAGS_PHILO	=	-pthread  -lpthread
RM			=	rm -f 

SRC			=	main.c							\
				src/parser/parser.c				\
				src/parser/error.c 				\
				tools/libft_tools/ft_strlen.c	\
				tools/libft_tools/ft_atoi.c		\

GREEN		=	\033[32;1m
RED			=	\033[0;31m
CYAN		=	\033[0;36m

OBJ			=	${SRC:.c=.o}

$(NAME): $(OBJ)
	@${CC} ${FLAGS} ${OBJ} -o ${NAME}
	@echo "$(GREEN) philo compiled succesfully!"

all: $(NAME)

clean:
	@${RM} ${OBJ}
	@echo "\033[0;33mobject files of philo were removed."

fclean: clean
	@${RM} ${NAME}
	@echo "\033[0;33m$(NAME) file  was also removed."

re: fclean all

.PHONY: all clean fclean re


# gcc -Wall -Wextra -Werror -pthread  -lpthread threads_main.c -o threads_main