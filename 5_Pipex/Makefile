# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 18:11:53 by jaewchoi          #+#    #+#              #
#    Updated: 2022/04/02 04:17:52 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

PRINTF = ./printf/libftprintf.a

INCLUDE = ./include/

SSRC = ./share/ft_first_cmd.c ./share/ft_get_path.c ./share/ft_last_cmd.c\
	  ./share/ft_open_file.c ./share/ft_perror.c ./share/ft_prog_name.c

MSRC = ./mandatory/main.c

BSRC = ./bonus/main_bonus.c ./bonus/ft_mid_cmd_bonus.c

SOBJ = $(SSRC:.c=.o)

MOBJ = $(MSRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

ifndef OBJECT
	OBJECT = $(MOBJ) $(SOBJ) 
endif

all : $(NAME)

clean :
	@$(MAKE) -C ./printf fclean
	@rm -f $(SOBJ) $(MOBJ) $(BOBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus :
	@make "OBJECT = $(BOBJ) $(SOBJ)" $(NAME)

$(NAME) : $(OBJECT) $(PRINTF)
	@$(CC) $(CFLAG) -o $(NAME) $(PRINTF) $(OBJECT)

$(PRINTF) :
	@$(MAKE) -C ./printf all

%.o : %.c
	@$(CC) $(CFLAG) -I $(INCLUDE) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
