# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 19:42:21 by jaewchoi          #+#    #+#              #
#    Updated: 2022/04/13 19:49:02 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./mandatory/main.c ./mandatory/ft_create_exe_file.c\
	  ./mandatory/ft_exec_file.c ./mandatory/ft_perror.c\
	  ./mandatory/ft_write_exe_file.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
