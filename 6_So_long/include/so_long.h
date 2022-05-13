/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:26:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/13 23:44:15 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X 0
# define Y 1
# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define X_DESTROY 17
# define SPACE "img/space.xpm"
# define WALL "img/wall.xpm"
# define ESCAPE_O "img/mirror1.xpm"
# define ESCAPE_C "img/mirror2.xpm"
# define MESO1 "img/meso1.xpm"
# define MESO2 "img/meso2.xpm"
# define MESO3 "img/meso3.xpm"
# define MESO4 "img/meso4.xpm"
# define MUSH1 "img/mushmom1.xpm"
# define MUSH2 "img/mushmom2.xpm"
# define MUSH3 "img/mushmom3.xpm"
# define MUSH4 "img/mushmom4.xpm"

#include <stdio.h>

typedef struct s_ele
{
	char			c;
	char			status;
	int				location;
	struct s_ele	*next;
	struct s_ele	*prev;
}	t_ele;

typedef struct s_map{
	char			**map;
	int				c;
	int				e;
	int				p;
	int				x;
	int				y;
	int				p_loc;
	struct s_ele	*list;
}	t_map;

typedef struct s_mlx_inst{
	void			*mlx;
	void			*win;
	void			*space;
	void			*wall;
	void			*meso1;
	void			*meso2;
	void			*meso3;
	void			*meso4;
	void			*mush1;
	void			*mush2;
	void			*mush3;
	void			*mush4;
	void			*escape1;
	void			*escape2;
	char			**map;
	char			key;
	int				p_loc;
	int				meso_cnt;
	char			motion;
	int				move_cnt;
	struct s_ele	*list;
}	t_mlx_inst;

void		ft_error(void);
char		**ft_parse_map(char *file);
t_map		ft_check_map(char **map);
void		ft_play_game(t_map data);
void		ft_inst_img(t_mlx_inst	*inst);
void		ft_create_map(t_mlx_inst inst, t_map data);
void		ft_put_img(t_mlx_inst inst, void *img, int *location);
void		ft_put_meso(t_mlx_inst *inst, t_ele *ele);
void		ft_put_escape(t_mlx_inst *inst, t_ele *ele);
int			ft_loop(t_mlx_inst *inst);
void		ft_del_map(t_map *data);
void		ft_put_mush(t_mlx_inst *inst);
void		ft_check_movable(int keycode, t_mlx_inst *inst);
void		ft_mush_up(t_mlx_inst *inst);
void		ft_mush_down(t_mlx_inst *inst);
void		ft_mush_left(t_mlx_inst *inst);
void		ft_mush_right(t_mlx_inst *inst);
void		ft_collect(t_mlx_inst *inst, int x, int y);

#endif
