# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 11:17:17 by fnieves           #+#    #+#              #
#    Updated: 2023/01/14 20:08:15 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC 			=	cc
FLAGS		=	-Wall -Wextra -Werror -g -pthread  -lpthread
FLAGS_PHILO	=	-pthread  -lpthread
RM			=	rm -f 

OBJ			=	$(SRC:.c=.o)
SRC			=	main.c								\
				src/parser/parser.c					\
				src/parser/error.c 					\
				src/libft_tools/ft_strlen.c			\
				src/libft_tools/atoi_phi.c			\
				src/libft_tools/ft_calloc.c			\
				src/initialize/initialize.c			\
				src/create/create.c					\
				src/create/time.c					\
				src/create/eats.c					\
				src/join/join.c						\


GREEN		=	\033[32;1m
RED			=	\033[0;31m
CYAN		=	\033[0;36m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
PINK		=	\033[1;35m
RESET		=	\e[0m


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) $(NAME) compiled succesfully!"

clean:
	@${RM} ${OBJ}
	@echo "$(YELLOW)object files of philo were removed."

fclean: clean
	@${RM} ${NAME}
	@echo "$(BLUE)$(NAME) file  was also removed."

re: fclean all

.PHONY: all clean fclean re
