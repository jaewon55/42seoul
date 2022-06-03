NAME = minishell

CC = gcc
CFLAG = -Werror -Wall -Wextra
OFLAG = -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
SRCS = srcs/mini.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

re : fclean all

$(NAME) : $(OBJS)
	$(CC) $(OFLAG) $(CFLAG) -o $@ $^

.PHONY : re fclean clean all 
