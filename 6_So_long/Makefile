# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:42:32 by jaewchoi          #+#    #+#              #
#    Updated: 2022/05/15 15:50:31 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft/libft.a

LIBFT_PATH = ./libft/

INCLUDE = ./include/

SSRC = ./share/ft_check_map_file_extension.c ./share/ft_del_map.c\
	   ./share/ft_error.c ./share/ft_parse_map.c ./share/ft_put_img.c

MSRC = ./src/main.c ./src/ft_check_map.c ./src/ft_check_movable.c\
	   ./src/ft_create_map.c ./src/ft_del_inst.c ./src/ft_get_inst.c\
	   ./src/ft_inst_img.c ./src/ft_move.c ./src/ft_play_game.c

BSRC = ./bonus/main_bonus.c ./bonus/ft_check_map_bonus.c\
	   ./bonus/ft_check_movable_bonus.c ./bonus/ft_collect_bonus.c\
	   ./bonus/ft_create_map_bonus.c ./bonus/ft_del_inst_bonus.c\
	   ./bonus/ft_game_clear_bonus.c ./bonus/ft_get_inst_bonus.c\
	   ./bonus/ft_inst_img_bonus.c ./bonus/ft_loop_bonus.c\
	   ./bonus/ft_mush_dead_bonus.c ./bonus/ft_mush_down_bonus.c\
	   ./bonus/ft_mush_left_bonus.c ./bonus/ft_mush_right_bonus.c\
	   ./bonus/ft_mush_up_bonus.c ./bonus/ft_play_game_bonus.c\
	   ./bonus/ft_put_escape_bonus.c ./bonus/ft_put_meso_bonus.c\
	   ./bonus/ft_put_mush_bonus.c
# -L [디렉토리] : 라이브러리를 찾을 디렉토리 지정
# -l : 같이 링크할 라이브러리를 지정한다.

SOBJ = $(SSRC:.c=.o)

MOBJ = $(MSRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

MLXFLAG = -L ./mlx -lmlx -framework OpenGL -framework Appkit

ifndef OBJECT
	OBJECT = $(MOBJ) $(SOBJ)
endif

all : $(NAME)

clean :
	@$(MAKE) -s -C $(LIBFT_PATH) fclean
	@$(MAKE) -s -C mlx clean
	@rm -f $(SOBJ) $(MOBJ) $(BOBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus :
	@$(MAKE) "OBJECT = $(BOBJ) $(SOBJ)" all

$(NAME) : $(OBJECT) $(LIBFT)
	@$(MAKE) -s -C mlx all
	@$(CC) $(CFLAG) $(MLXFLAG) $(OBJECT) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@$(MAKE) -s -C $(LIBFT_PATH) all

%.o : %.c
	@$(CC) $(CFLAG) -I $(INCLUDE) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
