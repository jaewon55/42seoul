#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void	*win;
	void	*img;
	void	*img2;
	void	*mlx;
	int		a;
	int		b;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1024, "so_long");
	img = mlx_xpm_file_to_image(mlx, "./img/space.xpm", &a, &b);
	img2 = mlx_xpm_file_to_image(mlx, "./img/mushmom1.xpm", &a, &b);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 0, 0);
	mlx_loop(mlx);
	return (0);
}
