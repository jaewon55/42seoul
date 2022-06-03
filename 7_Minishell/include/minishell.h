#ifndef MINISHELL_H
# define MINISHELL_H
# include "bintree.h"

enum e_token_type
{
	CMD = 0,
	REDI_L,
	REDI_R,
	DREDI_L,
	DREDI_R
};

typedef struct s_token
{
	int		type;
	char	*token;
}			t_token;

// t_tree	*parser(char *str);
void	ft_error(char *);

#endif