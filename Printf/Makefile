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

SRC = ./src/ft_printf.c ./src/ft_putnstr.c ./src/get_field.c ./src/handling_conversion.c\
	./src/handling_int.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

clean :
	@$(MAKE) -C ./libft clean
	@rm -f ./src/*.o

fclean : clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft bonus
	@ar -rcs $@ $^ ./libft/$(LIBFT)

%.o : %.c
	@gcc $(CFLAG) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
