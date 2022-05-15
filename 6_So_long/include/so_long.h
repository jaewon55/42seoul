/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:26:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 15:27:03 by jaewchoi         ###   ########.fr       */
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
# define ESCAPE "img/mirror1.xpm"
# define MESO "img/meso2.xpm"
# define MUSH "img/Mushmom1.xpm"

typedef struct s_map{
	char			**map;
	int				c;
	int				e;
	int				p;
	int				x;
	int				y;
	int				p_loc;
}	t_map;

typedef struct s_mlx_inst{
	void			*mlx;
	void			*win;
	void			*space;
	void			*wall;
	void			*meso;
	void			*mush;
	void			*escape;
	char			**map;
	char			key;
	int				p_loc;
	int				meso_cnt;
	int				move_cnt;
	struct s_ele	*list;
}	t_mlx_inst;

int			ft_check_map_file_extension(char *file);
void		ft_del_map(char **data);
void		ft_error(char *str);
char		**ft_parse_map(char *file);
void		ft_put_img(t_mlx_inst inst, void *img, int *location);
t_map		ft_check_map(char **map);
int			ft_check_movable(int keycode, t_mlx_inst *inst);
void		ft_create_map(t_mlx_inst inst, t_map data);
void		ft_del_inst(t_mlx_inst *inst);
t_mlx_inst	ft_get_inst(t_map map_data);
void		ft_inst_img(t_mlx_inst	*inst);
void		ft_move(t_mlx_inst *inst);
void		ft_play_game(t_map data);

#endif
