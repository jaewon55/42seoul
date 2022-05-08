#include "mlx.h"

int main(void)
{
	void    *win;
	void    *img;
	void    *mlx;
	int     a;
	int     b;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1024, 512, "so_long");
	img = mlx_xpm_to_image(mlx, "./img/mushmom.xpm", &a, &b);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
