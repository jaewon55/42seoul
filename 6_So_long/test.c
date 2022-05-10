#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define SPACE "img/space.xpm"

int main(void)
{
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*mlx;
	int		a;
	int		b;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 64 * 39, 64 * 21, "so_long");
	img = mlx_xpm_file_to_image(mlx, SPACE, &a, &b);
	img2 = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &a, &b);
	img3 = mlx_xpm_file_to_image(mlx, "img/mirror1.xpm", &a, &b);
	img4 = mlx_xpm_file_to_image(mlx, "img/mirror2.xpm", &a, &b);
	img5 = mlx_xpm_file_to_image(mlx, "img/mushmom1.xpm", &a, &b);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 0);
	mlx_put_image_to_window(mlx, win, img5, 0, 0);
	mlx_loop(mlx);
	return (0);
}
