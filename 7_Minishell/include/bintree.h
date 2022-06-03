#ifndef BINTREE_H
# define BINTREE_H
# include "minishell.h"

typedef struct s_tree_node
{
	t_token	data;
	int		visited;

	struct s_tree_node	*left;
	struct s_tree_node	*right;
} t_tree_node;

typedef struct s_tree
{
	struct s_tree_node	*root;
} t_tree;

t_tree		*create_bin_tree(t_tree_node root_node);
t_tree_node	*insert_left_node(t_tree_node *parent, t_tree_node child);
t_tree_node	*insert_right_node(t_tree_node *parent, t_tree_node child);
static void	delorder(t_tree_node **node);
void		delete_tree(t_tree *tree);


#endif