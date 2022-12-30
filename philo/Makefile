# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 11:17:17 by fnieves           #+#    #+#              #
#    Updated: 2022/12/30 16:13:22 by fnieves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
FLAGS		=	-Wall -Wextra #-Werror
FLAGS_PHILO	=	-pthread  -lpthread
FLAGS_LEAKS	=	-g -fsanitize=thread
RM			=	rm -f
INCFLAGS	= -I include

NAME		= 	philo
HEADER		=	include/philo.h

SRC			=	main.c					\
				src/parser/parser.c		\
				tools/libft_tools/ft_strlen.c
				# src/parser/parser.c		\
				# tools/libft_tools/ft_strlen.c

GREEN		=	\033[32;1m
RED			=	\033[0;31m
CYAN		=	\033[0;36m

OBJ			=	$(addprefix obj/,$(notdir $(SRC:.c=.o)))
OBJ2		=	${SRC:.c=.o}

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "$(GREEN) philo compiled succesfully!"

obj/%.o: %.c $(HEADER) | obj
	@$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@

obj:
	@echo "\033[32;1m\tphilo is compiling..."
	@mkdir obj

all: $(NAME)

clean:
	@${RM} ${OBJ}
	@echo "\033[0;33mobject files of philo were removed."

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


# gcc -Wall -Wextra -Werror -pthread  -lpthread threads_main.c -o threads_main

# what means in make file the next expression? obj/%.o : %.c $(HEADER) | obj
# 	@$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@

# In a Makefile, the expression obj/%.o : %.c $(HEADER) | obj defines
# a pattern rule. Pattern rules are used to specify how to build targets
# that match a certain pattern.
# In this particular pattern rule, the target is obj/%.o, which means
# that it will match any target of the form obj/something.o, where
# something can be any string. The %.o and %.c parts of the target and dependency are called "wildcards". They are used
# to match any string, so that the rule can be applied to a wide range of targets.
# The $(HEADER) dependency specifies that the target depends on a 
# list of header files. This means that the rule will be executed whenever any of the header files are modified.
# The | obj part of the rule specifies an order-only dependency on the obj
# directory. This means that the obj directory must exist before the rule
# is executed, but the modification time of the directory does not affect when the rule is executed.
# The command @$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@ specifies the 
# command to be run when the rule is executed. The $(CC) variable specifies the compiler
#  to be used. The $(FLAGS) and $(INCFLAGS) variables specify compiler flags and include directories, respectively. The $< symbol represents
# the first dependency (the source file), and the $@ symbol represents the target (the object file).
# In this example, the rule specifies that a target of the form obj/something.o can be built by compiling
#  the corresponding source file something.c and any specified header files. The object file will be placed in the obj directory.

