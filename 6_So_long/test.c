#include "mlx.h"

int main(void)
{
    void    *win;
    void    *img;
    void    *mlx;
    int     a;
    int     b;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 600, "hello");
    img = mlx_xpm_file_to_image(mlx, "./img/mushroom1.xpm", &a, &b);
    mlx_put_image_to_window(mlx, win, img, 300, 300);
    mlx_loop(mlx);
	return (0);
}
