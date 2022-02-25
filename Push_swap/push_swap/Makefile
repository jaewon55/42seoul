# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 20:51:18 by jaewchoi          #+#    #+#              #
#    Updated: 2022/02/25 21:21:22 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_push_to_b.c ft_push_to_a.c ft_list_del.c\
	  ft_list_len.c ft_make_stack.c ft_merge_sort.c\
	  ft_parsing_av.c ft_push_swap.c ft_putstr.c\
	  ft_sorted_arr.c ft_split_num.c ft_stack_del.c\
	  ft_sort_a.c ft_three_sort.c ft_quarter_b.c\
	  ft_push_a_utils.c\
	  main.c test.c 

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

all : $(NAME)

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	@gcc -g $(SRC) -o $(NAME)
#	@$(CC) $(CFLAG) -o $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re
