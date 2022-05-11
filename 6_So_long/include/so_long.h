/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:26:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/11 18:21:55 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X 0
# define Y 1
# define K_ESC 53
# define X_DESTROY 17
# define SPACE "img/space.xpm"
# define WALL "img/wall.xpm"
# define ESCAPE_O "img/mirror1.xpm"
# define ESCAPE_C "img/mirror2.xpm"
# define MESO "img/meso.xpm"
# define PLAYER "img/mushmom1.xpm"

#include <stdio.h>

typedef struct s_map_data{
	char	**map;
	int		c;
	int		e;
	int		p;
	int		x;
	int		y;
}	t_map_data;

typedef struct s_mlx_instance{
	void	*mlx;
	void	*win;
}	t_mlx_instance;

void		ft_error(void);
char		**ft_parse_map(char *file);
t_map_data	ft_check_map(char **map);
void		ft_play_game(t_map_data data);
void		ft_create_map(t_mlx_instance instance, t_map_data data);
void		ft_put_img(t_mlx_instance instance, char *file, int *location);


#endif
