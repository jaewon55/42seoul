# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 18:11:53 by jaewchoi          #+#    #+#              #
#    Updated: 2022/04/01 18:57:02 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

PRINTF = libftprintf.a

SRC = ft_first_cmd.c ft_get_path.c ft_last_cmd.c\
	  ft_open_file.c ft_perror.c ft_prog_name.c\
	  main.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

clean :
	@$(MAKE) -C ./printf fclean
	@rm -f $(OBJ)

fclean : clean
	@$(MAKE) -C ./printf fclean
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	@$(MAKE) -C ./printf all
	@$(CC) $(CFLAG) -o $(NAME) ./printf/$(PRINTF) $(OBJ)

%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
