#ifndef PARSER_H
# define PARSER_H

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

typedef struct s_tree
{

}			t_tree;

t_tree	*parser(char *str);

#endif
