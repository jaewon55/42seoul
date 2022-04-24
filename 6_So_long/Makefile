# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:42:32 by jaewchoi          #+#    #+#              #
#    Updated: 2022/04/22 17:50:10 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDE = ./mlx/

SRC = ./main.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	@$(CC) $(CFLAG) -L ./mlx -lmlx -framework OpenGL \
		-framework Appkit $(OBJ) -o $(NAME)
# -L [디렉토리] : 라이브러리를 찾을 디렉토리 지정
# -l : 같이 링크할 라이브러리를 지정한다.
%.o : %.c
	@$(CC) -I $(INCLUDE) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
