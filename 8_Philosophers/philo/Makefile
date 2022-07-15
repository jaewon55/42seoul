# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 14:39:32 by jaewchoi          #+#    #+#              #
#    Updated: 2022/07/16 01:57:22 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./ft_atoi.c ./ft_create_arg.c ./ft_create_philo_list.c \
	  ./ft_create_philo.c ./ft_error_util.c ./ft_lst_util.c \
	  ./ft_philo_routine.c ./philo.c ./ft_create_watcher.c \
	  ./ft_ms_time_util.c ./ft_mutex_util.c ./ft_odd_philo_routine.c \
	  ./ft_philo_action.c ./ft_watcher_routine.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror -g

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $(^:.c=.o)
