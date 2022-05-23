# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 13:18:08 by jaewchoi          #+#    #+#              #
#    Updated: 2022/01/13 17:24:12 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

SRC = ./mandatory/ft_printf.c ./mandatory/check_error.c\
	  ./mandatory/get_precision.c ./mandatory/get_width.c\
	  ./mandatory/handling_conversion.c ./mandatory/handling_char.c\
	  ./mandatory/handling_int.c ./mandatory/handling_uint.c\
	  ./mandatory/handling_ptr.c ./mandatory/handling_str.c\
	  ./mandatory/nbr_len.c	./mandatory/write_blank.c\
	  ./mandatory/write_char.c ./mandatory/write_nbr.c\
	  ./mandatory/write_str.c ./mandatory/ft_putnstr.c

OBJ = $(SRC:.c=.o)

BSRC = ./bonus/ft_printf_bonus.c ./bonus/check_error_bonus.c\
	   ./bonus/get_precision_bonus.c ./bonus/get_width_bonus.c\
	   ./bonus/handling_conversion_bonus.c ./bonus/handling_char_bonus.c\
	   ./bonus/handling_int_bonus.c ./bonus/handling_uint_bonus.c\
	   ./bonus/handling_ptr_bonus.c ./bonus/handling_str_bonus.c\
	   ./bonus/nbr_len_bonus.c	./bonus/write_blank_bonus.c\
	   ./bonus/write_char_bonus.c ./bonus/write_nbr_bonus.c\
	   ./bonus/write_str_bonus.c ./bonus/ft_putnstr_bonus.c

BOBJ = $(BSRC:.c=.o)

ifeq ($(WITH_BONUS), true)
	OBJECT = $(BOBJ)
else
	OBJECT = $(OBJ)
endif

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

clean :
	@rm -f $(OBJ) $(BOBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus :
	@make WITH_BONUS=true all

$(NAME) : $(OBJECT)
	@$(MAKE) -C ./libft bonus
	@cp ./libft/$(LIBFT) ./$@
	@$(MAKE) -C ./libft fclean
	@ar rcs $@ $^

%.o : %.c
	@gcc $(CFLAG) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
