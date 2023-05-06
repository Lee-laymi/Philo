# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 17:10:36 by skrairab          #+#    #+#              #
#    Updated: 2023/05/07 03:06:30 by skrairab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_basic.c\
		ft_check_error.c\
		ft_split.c\
		philo.c\
		routines.c\
		ft_create_philo.c\
		ft_createthread.c\
		ft_time.c\
		ft_checkdie.c\

NAME = philo

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS =   -Wall -Wextra -Werror  -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME) -g 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf philo.dSYM

re: fclean all

a: re
	./philo 1 800 200 200

b: re
	./philo 5 800 200 200

c: re
	./philo 5 800 200 200 2

d: re
	./philo 4 410 200 200

e: re
	./philo 4 310 200 100

f: re
	./philo 0 100 50 40

g: re
	./philo 4 400 "" 100

h: re
	./philo 50 300 100 100 4

i: re
	valgrind --leak-check=full ./philo 4 310 200 200

j: re
	valgrind --leak-check=full ./philo 5 800 200 200 2

.PHONY: all clean fclean re