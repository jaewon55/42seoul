#include "mlx.h"

int main(void)
{
void    *img;
    void    *mlx;

    mlx = mlx_init();
    img = mlx_new_window(mlx, 500, 500, "hello");
    mlx_loop(mlx);
	return (0);
}
