#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SPACE "img/space.xpm"

typedef struct s_instance{
	void	*mlx;
	void	*win;
} t_instance ;

int	ft_close(t_instance *instance)
{
	exit(0);
	return (1);
}

void	ft_remove(t_instance *instance)
{
	int	a;
	int	b;
	void	*space = mlx_xpm_file_to_image(instance->mlx, SPACE, &a, &b);
	mlx_put_image_to_window(instance->mlx, instance->win, space, 0, 0);
	mlx_put_image_to_window(instance->mlx, instance->win, space, 64, 0);
}

void	ft_rmove(t_instance *instance)
{
	int	a;
	int	b;
	void	*img1 = mlx_xpm_file_to_image(instance->mlx, "img/mushmom1.xpm", &a, &b);
	void	*img2 = mlx_xpm_file_to_image(instance->mlx, "img/mushmom2.xpm", &a, &b);
	void	*img3 = mlx_xpm_file_to_image(instance->mlx, "img/mushmom3.xpm", &a, &b);
	void	*img4 = mlx_xpm_file_to_image(instance->mlx, "img/mushmom4.xpm", &a, &b);
	ft_remove(instance);
	mlx_put_image_to_window(instance->mlx, instance->win, img2, 16, 0);
	mlx_do_sync(instance->mlx);
	ft_remove(instance);
	mlx_put_image_to_window(instance->mlx, instance->win, img3, 32, 0);
	mlx_do_sync(instance->mlx);
	ft_remove(instance);
	mlx_put_image_to_window(instance->mlx, instance->win, img4, 48, 0);
	mlx_do_sync(instance->mlx);
	ft_remove(instance);
	mlx_put_image_to_window(instance->mlx, instance->win, img1, 64, 0);
}

void	ft_lmove(t_instance *instance)
{
	int	a;
	int	b;
	void	*img1 = mlx_xpm_file_to_image(instance->mlx, "img/mushmom1.xpm", &a, &b);
	void	*img2 = mlx_xpm_file_to_image(instance->mlx, "img/mushmom2.xpm", &a, &b);
	void	*img3 = mlx_xpm_file_to_image(instance->mlx, "img/mushmom3.xpm", &a, &b);
	void	*img4 = mlx_xpm_file_to_image(instance->mlx, "img/mushmom4.xpm", &a, &b);
	ft_remove(instance);
	mlx_put_image_to_window(instance->mlx, instance->win, img2, 48, 0);
	mlx_do_sync(instance->mlx);
	ft_remove(instance);
	mlx_put_image_to_window(instance->mlx, instance->win, img3, 32, 0);
	mlx_do_sync(instance->mlx);
	ft_remove(instance);
	mlx_put_image_to_window(instance->mlx, instance->win, img4, 16, 0);
	mlx_do_sync(instance->mlx);
	ft_remove(instance);
	mlx_put_image_to_window(instance->mlx, instance->win, img1, 0, 0);
}

int ft_esc(int keycode, t_instance *instance)
{
	if (keycode == 53)
		ft_close(instance);
	else if (keycode == 2)
		ft_rmove(instance);
	else if (keycode == 0)
		ft_lmove(instance);
	return 1;
}

int	ft_print()
{
	printf("1\n");
	return (1);
}

int main(void)
{
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*mlx;
	int		a;
	int		b;
	int		x = 0;
	t_instance instance;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 64 * 3, 128, "so_long");
	img = mlx_xpm_file_to_image(mlx, SPACE, &a, &b);
	img2 = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &a, &b);
	img3 = mlx_xpm_file_to_image(mlx, "img/mirror1.xpm", &a, &b);
	img4 = mlx_xpm_file_to_image(mlx, "img/mirror2.xpm", &a, &b);
	img5 = mlx_xpm_file_to_image(mlx, "img/mushmom1.xpm", &a, &b);
	img6 = mlx_xpm_file_to_image(mlx, "img/meso.xpm", &a, &b);
	mlx_put_image_to_window(mlx, win, img, x++ * 64, 0);
	mlx_put_image_to_window(mlx, win, img, x++ * 64, 0);
	mlx_put_image_to_window(mlx, win, img, x++ * 64, 0);
	x = 0;
	mlx_put_image_to_window(mlx, win, img, x++ * 64, 64);
	mlx_put_image_to_window(mlx, win, img, x++ * 64, 64);
	mlx_put_image_to_window(mlx, win, img, x++ * 64, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 0);
	instance.mlx = mlx;
	instance.win = win;
	mlx_hook(win, 17, 0, ft_close, &instance);
	mlx_key_hook(win, ft_esc, &instance);
	mlx_loop(mlx);
	return (0);
}
