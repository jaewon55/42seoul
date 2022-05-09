/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:26:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/09 20:52:55 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>

typedef struct s_map_data{
	int	c;
	int	e;
	int	p;
	int	x;
	int	y;
}	t_map_data;

typedef struct s_mlx_instance{
	void	*mlx;
	void	*win;
}	t_mlx_instance;

void		ft_error(void);
char		**ft_parse_map(char *file);
t_map_data	ft_check_map(char **map);

#endif
