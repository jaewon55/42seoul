# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 20:51:18 by jaewchoi          #+#    #+#              #
#    Updated: 2022/03/19 13:12:01 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRC = ./mandatory/ft_merge_sort.c ./mandatory/ft_push_a_utils.c\
	  ./mandatory/ft_push_swap.c ./mandatory/ft_push_to_a.c\
	  ./mandatory/ft_push_to_b.c ./mandatory/ft_putstr.c\
	  ./mandatory/ft_quarter_b.c ./mandatory/ft_sort_a.c\
	  ./mandatory/ft_sorted_arr.c ./mandatory/ft_three_sort.c\
	  ./mandatory/ft_two_pre_num.c ./mandatory/main.c

SSRC = ./share/ft_itoa.c ./share/ft_list_del.c ./share/ft_list_len.c\
	   ./share/ft_parsing.c ./share/ft_split_list.c ./share/ft_stack_del.c\
	   ./share/ft_error.c ./share/ft_stack_create.c

BSRC = ./bonus/ft_check_rule_bonus.c ./bonus/ft_gnl_bonus.c\
	   ./bonus/ft_gnl_utils_bonus.c ./bonus/ft_push_rule_bonus.c\
	   ./bonus/ft_rot_rule_bonus.c ./bonus/ft_rrot_rule_bonus.c\
	   ./bonus/ft_swap_rule_bonus.c ./bonus/main_bonus.c

OBJ = $(SRC:.c=.o)

SOBJ = $(SSRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

bonus : $(NAME) $(BONUS)

clean :
	@$(RM) $(OBJ) $(SOBJ) $(BOBJ)

fclean : clean
	@$(RM) $(NAME) $(BONUS)

re : fclean all

$(NAME) : $(OBJ) $(SOBJ)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(SOBJ)

$(BONUS) : $(BOBJ) $(SOBJ)
	@$(CC) $(CFLAG) -o $(BONUS) $(BOBJ) $(SOBJ)

%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $(^:.c=.o)

.PHONY : all bonus clean fclean re
