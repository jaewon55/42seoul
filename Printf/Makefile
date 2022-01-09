# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 13:18:08 by jaewchoi          #+#    #+#              #
#    Updated: 2021/12/24 14:00:33 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

SRC = ./mandatory/ft_printf.c ./mandatory/handling_conversion.c\
	  ./mandatory/write_char.c ./mandatory/write_nbr.c ./mandatory/write_str.c

BSRC

ifeq ($(WITH_BONUS), true)
	OBJ = $(BSRC:.c=.o)
else
	OBJ = $(SRC:.c=.o)
endif

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

clean :
	@$(MAKE) -C ./libft clean
	@rm -f $(OBJ)

fclean : clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re : fclean all

bonus :
	@make WITH_BONUS=true all

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft bonus
	@cp ./libft/$(LIBFT) ./$@
	@ar rcs $@ $^

%.o : %.c
	@gcc $(CFLAG) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
