#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SPACE "img/space.xpm"
#define MESO1 "img/meso1.xpm"
#define MESO2 "img/meso2.xpm"
#define MESO3 "img/meso3.xpm"
#define MESO4 "img/meso4.xpm"
#define MUSH1 "img/mushmom1.xpm"
#define MUSH2 "img/mushmom2.xpm"
#define MUSH3 "img/mushmom3.xpm"
#define MUSH4 "img/mushmom4.xpm"

typedef struct s_instance{
	void	*mlx;
	void	*win;
	void	*space;
	void	*meso1;
	void	*meso2;
	void	*meso3;
	void	*meso4;
	void	*mush1;
	void	*mush2;
	void	*mush3;
	void	*mush4;
	int		i;
	int		right;
	int		left;
	int		mush_img;
	int		loc[2];
} t_instance ;

int	ft_close(t_instance *instance)
{
	exit(0);
	return (1);
}

int ft_esc(int keycode, t_instance *instance)
{
	if (keycode == 53)
		ft_close(instance);
	if (keycode == 0)
		instance->left = 1;
	if (keycode == 2)
		instance->right = 1;
	return 1;
}

void	ft_mush(t_instance *ins)
{
	if (!ins->left && !ins->right)
		mlx_put_image_to_window(ins->mlx, ins->win, ins->mush1, ins->loc[0], ins->loc[1]);
	else if (ins->right)
	{
		if (ins->mush_img == 1)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush2, ins->loc[0], ins->loc[1]);
			ins->mush_img++;
		}
		else if (ins->mush_img == 2)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush3, ins->loc[0], ins->loc[1]);
			ins->mush_img++;
		}
		else if (ins->mush_img == 3)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			ins->loc[0] += 16;
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush4, ins->loc[0], ins->loc[1] - 16);
			ins->mush_img++;
		}
		else if (ins->mush_img == 4)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			ins->loc[0] += 16;
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush4, ins->loc[0], ins->loc[1] - 16);
			ins->mush_img++;
		}
		else if (ins->mush_img == 5)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			ins->loc[0] += 16;
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush4, ins->loc[0], ins->loc[1] - 16);
			ins->mush_img++;
		}
		else if (ins->mush_img == 6)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			ins->loc[0] += 16;
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush4, ins->loc[0], ins->loc[1] - 16);
			ins->mush_img++;
		}
		else if (ins->mush_img == 7)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush2, ins->loc[0], ins->loc[1]);
			ins->mush_img++;
		}
		else if (ins->mush_img == 8)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush1, ins->loc[0], ins->loc[1]);
			ins->mush_img = 1;
			ins->right = 0;
		}
	}
	else if (ins->left)
	{
		if (ins->mush_img == 1)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush2, ins->loc[0], ins->loc[1]);
			ins->mush_img++;
		}
		else if (ins->mush_img == 2)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush3, ins->loc[0], ins->loc[1]);
			ins->mush_img++;
		}
		else if (ins->mush_img == 3)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			ins->loc[0] -= 16;
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush4, ins->loc[0], ins->loc[1] - 16);
			ins->mush_img++;
		}
		else if (ins->mush_img == 4)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			ins->loc[0] -= 16;
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush4, ins->loc[0], ins->loc[1] - 16);
			ins->mush_img++;
		}
		else if (ins->mush_img == 5)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			ins->loc[0] -= 16;
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush4, ins->loc[0], ins->loc[1] - 16);
			ins->mush_img++;
		}
		else if (ins->mush_img == 6)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			ins->loc[0] -= 16;
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush4, ins->loc[0], ins->loc[1] - 16);
			ins->mush_img++;
		}
		else if (ins->mush_img == 7)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush2, ins->loc[0], ins->loc[1]);
			ins->mush_img++;
		}
		else if (ins->mush_img == 8)
		{
			mlx_put_image_to_window(ins->mlx, ins->win, ins->space, ins->loc[0], ins->loc[1]);
			mlx_put_image_to_window(ins->mlx, ins->win, ins->mush1, ins->loc[0], ins->loc[1]);
			ins->mush_img = 1;
			ins->left = 0;
		}
	}
}

int	ft_loop(t_instance *instance)
{
	mlx_do_sync(instance->mlx);
	mlx_do_sync(instance->mlx);
	mlx_do_sync(instance->mlx);
	if (instance->i == 1)
	{
		mlx_put_image_to_window(instance->space, instance->win, instance->meso1, 0, 0);
		instance->i++;
	}
	else if (instance->i == 2)
	{
		mlx_put_image_to_window(instance->space, instance->win, instance->meso2, 0, 0);
		instance->i++;
	}	
	else if (instance->i == 3)
	{
		mlx_put_image_to_window(instance->space, instance->win, instance->meso3, 0, 0);
		instance->i++;
	}
	else if (instance->i == 4)
	{
		mlx_put_image_to_window(instance->space, instance->win, instance->meso4, 0, 0);
		instance->i = 1;
	}
	ft_mush(instance);
	return 1;
}

int main(void)
{
	int		a;
	int		b;
	t_instance instance;

	instance.mlx = mlx_init();
	instance.win = mlx_new_window(instance.mlx, 128, 128, "so_long");
	instance.i = 1;
	instance.left = 0;
	instance.right = 0;
	instance.loc[0] = 0;
	instance.loc[1] = 64;
	instance.space = mlx_xpm_file_to_image(instance.mlx, SPACE, &a, &b);
	instance.meso1 = mlx_xpm_file_to_image(instance.mlx, MESO1, &a, &b);
	instance.meso2 = mlx_xpm_file_to_image(instance.mlx, MESO2, &a, &b);
	instance.meso3 = mlx_xpm_file_to_image(instance.mlx, MESO3, &a, &b);
	instance.meso4 = mlx_xpm_file_to_image(instance.mlx, MESO4, &a, &b);
	instance.mush1 = mlx_xpm_file_to_image(instance.mlx, MUSH1, &a, &b);
	instance.mush2 = mlx_xpm_file_to_image(instance.mlx, MUSH2, &a, &b);
	instance.mush3 = mlx_xpm_file_to_image(instance.mlx, MUSH3, &a, &b);
	instance.mush4 = mlx_xpm_file_to_image(instance.mlx, MUSH4, &a, &b);
	mlx_string_put(instance.mlx, instance.win, 80, 32, 0x000000, "123");
	mlx_put_image_to_window(instance.space, instance.win, instance.space, 64, 0);
	mlx_put_image_to_window(instance.space, instance.win, instance.space, 0, 64);
	mlx_put_image_to_window(instance.space, instance.win, instance.space, 64, 64);
	mlx_hook(instance.win, 17, 0, ft_close, &instance);
	mlx_key_hook(instance.win, ft_esc, &instance);
	mlx_loop_hook(instance.mlx, ft_loop, &instance);
	mlx_loop(instance.mlx);
	return (0);
}
