# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:42:32 by jaewchoi          #+#    #+#              #
#    Updated: 2022/05/09 15:29:13 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft/libft.a

LIBFT_PATH = ./libft/

INCLUDE = ./include/

SRC = test.c
#./src/main.c ./src/ft_check_map.c ./src/ft_error.c\
	  ./src/ft_parse_map.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

clean :
# @$(MAKE) -s -C $(LIBFT_PATH) fclean
# @$(MAKE) -s -C mlx clean
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(LIBFT) :
	@$(MAKE) -s -C $(LIBFT_PATH) all

$(NAME) : $(OBJ) $(LIBFT)
# @$(MAKE) -s -C mlx all
	@$(CC) $(CFLAG) -L ./mlx -lmlx -framework OpenGL \
		-framework Appkit $(OBJ) $(LIBFT) -o $(NAME)
# -L [디렉토리] : 라이브러리를 찾을 디렉토리 지정
# -l : 같이 링크할 라이브러리를 지정한다.
%.o : %.c
	@$(CC) -I $(INCLUDE) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
