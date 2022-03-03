/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:20:57 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/03/03 17:20:57 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
typedef struct s_list
{
	int				content;
	size_t			idx;
	struct s_list	*pre;
	struct s_list	*next;
}	t_list;
t_list	*ft_parsing(int ac, char *av[]);
t_list	*ft_split_list(char *str, t_list *head);
ssize_t	ft_itoa(char **str);

#endif
