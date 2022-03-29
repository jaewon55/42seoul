# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 18:11:53 by jaewchoi          #+#    #+#              #
#    Updated: 2022/03/29 18:29:29 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft.a

SRC = ft_first_cmd.c ft_get_path.c ft_open_fd.c ft_perror.c\
	  ft_prog_name.c ft_second_cmd.c main.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

clean :
	@$(MAKE) -C ./libft fclean
	@rm -f $(OBJ)

fclean : clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft bonus
	@$(CC) $(CFLAG) -g -o $(NAME) ./libft/$(LIBFT) $(OBJ)
	@rm -f $(LIBFT)

%.o : %.c
	@$(CC) $(CFLAG) -c -g $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
