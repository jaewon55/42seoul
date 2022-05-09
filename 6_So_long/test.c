#include "mlx.h"
#include <stdio.h>

int main(void)
{
	void	*win;
	void	*img;
	void	*mlx;
	int		a;
	int		b;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1024, "so_long");
	img = mlx_xpm_file_to_image(mlx, "./img/tree.xpm", &a, &b);
	a = 100;
	b = 100;
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
