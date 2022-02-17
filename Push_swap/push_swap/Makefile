# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 20:51:18 by jaewchoi          #+#    #+#              #
#    Updated: 2022/02/17 21:12:54 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_half_to_a.c ft_half_to_b.c ft_in_swap.c ft_list_del.c\
	  ft_list_len.c ft_make_stack.c ft_merge_sort.c ft_out_swap.c\
	  ft_parsing_av.c ft_part.c ft_push_swap.c ft_putstr.c \
	  ft_quick_sort.c ft_sorted_arr.c ft_split_num.c ft_stack_del.c\
	  ft_swap.c main.c

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
# @$(CC) $(CFLAG) -o $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re
