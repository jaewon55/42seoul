/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:26:48 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/15 15:19:51 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define X 0
# define Y 1
# define K_ESC 53
# define K_SPACE 49
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define DEAD 10
# define CLEAR 11
# define X_DESTROY 17
# define SPACE "img/space.xpm"
# define WALL "img/wall.xpm"
# define ENEMY "img/enemy.xpm"
# define ESCAPE_O "img/mirror1.xpm"
# define ESCAPE_C "img/mirror2.xpm"
# define MESO1 "img/meso1.xpm"
# define MESO2 "img/meso2.xpm"
# define MESO3 "img/meso3.xpm"
# define MESO4 "img/meso4.xpm"
# define MUSH1 "img/Mushmom1.xpm"
# define MUSH2 "img/Mushmom2.xpm"
# define MUSH3 "img/Mushmom3.xpm"
# define MUSH4 "img/Mushmom4.xpm"
# define DIE1 "img/die1.xpm"
# define DIE2 "img/die2.xpm"
# define DIE3 "img/die3.xpm"
# define DIE4 "img/die4.xpm"
# define DIE5 "img/die5.xpm"
# define DIE6 "img/die6.xpm"

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
	void			*enemy;
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
	void			*die1;
	void			*die2;
	void			*die3;
	void			*die4;
	void			*die5;
	void			*die6;
	char			**map;
	int				cnt_loc;
	char			key;
	int				p_loc;
	int				meso_cnt;
	char			motion;
	int				move_cnt;
	struct s_ele	*list;
}	t_mlx_inst;

int			ft_check_map_file_extension(char *file);
void		ft_del_map(char **data);
void		ft_error(char *str);
char		**ft_parse_map(char *file);
void		ft_put_img(t_mlx_inst inst, void *img, int *location);
t_map		ft_check_map_b(char **map);
void		ft_check_movable_b(int keycode, t_mlx_inst *inst);
void		ft_collect_b(t_mlx_inst *inst, int x, int y);
void		ft_create_map_b(t_mlx_inst inst, t_map data);
void		ft_del_inst_b(t_mlx_inst *inst);
void		ft_game_clear(t_mlx_inst *inst);
t_mlx_inst	ft_get_inst_b(t_map map_data);
void		ft_inst_img_b(t_mlx_inst	*inst);
int			ft_loop(t_mlx_inst *inst);
void		ft_mush_dead(t_mlx_inst *inst, int *loc);
void		ft_mush_down(t_mlx_inst *inst, int *loc);
void		ft_mush_left(t_mlx_inst *inst, int *loc);
void		ft_mush_right(t_mlx_inst *inst, int *loc);
void		ft_mush_up(t_mlx_inst *inst, int *loc);
void		ft_play_game_b(t_map map_data);
void		ft_put_escape(t_mlx_inst *inst, t_ele *ele);
void		ft_put_meso(t_mlx_inst *inst, t_ele *ele);
void		ft_put_mush(t_mlx_inst *inst);

#endif
