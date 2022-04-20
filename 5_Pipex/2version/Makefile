# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 19:42:21 by jaewchoi          #+#    #+#              #
#    Updated: 2022/04/19 16:45:48 by jaewchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

INCLUDE = ./include/

SSRC = ./share/ft_create_exe_file.c ./share/ft_exec_file.c\
	   ./share/ft_perror.c ./share/ft_write_exe_file.c\
	   ./share/ft_strlen.c ./share/ft_strchr.c ./share/ft_putstr_fd.c

MSRC = ./mandatory/main.c

BSRC = ./bonus/main_bonus.c ./bonus/ft_gnl_bonus.c\
	   ./bonus/ft_here_doc_bonus.c ./bonus/ft_is_here_doc_bonus.c\
	   ./bonus/ft_multiple_pipe_bonus.c ./bonus/ft_quotes_limiter_bonus.c\
	   ./bonus/ft_unquotes_limiter_bonus.c ./bonus/ft_is_limiter_bonus.c\
	   ./bonus/ft_write_append_exe_file_bonus.c\
	   ./bonus/ft_write_stdin_bonus.c


SOBJ = $(SSRC:.c=.o)

MOBJ = $(MSRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

ifndef OBJECT
	OBJECT = $(MOBJ) $(SOBJ) 
endif

all : $(NAME)

clean :
	@rm -f $(SOBJ) $(MOBJ) $(BOBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus :
	@make "OBJECT = $(BOBJ) $(SOBJ)" all

$(NAME) : $(OBJECT)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJECT)

%.o : %.c
	@$(CC) $(CFLAG) -I $(INCLUDE) -c $^ -o $(^:.c=.o)

.PHONY : all clean fclean re bonus
