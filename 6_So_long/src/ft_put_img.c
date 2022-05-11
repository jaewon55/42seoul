/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:44:12 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/11 17:00:24 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static int	is_meso(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.')
		i++;
	if (file [i - 1] == 'o')
		return (1);
	return (0);
}

void	ft_put_img(t_mlx_instance instance, char *file, int *location)
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;

	img = mlx_xpm_file_to_image(instance.mlx, file, &width, &height);
	if (!img)
		ft_error();
	x = location[X];
	y = location[Y];
	if (is_meso(file))
	{
		x += 16;
		y += 16;
	}
	mlx_put_image_to_window(instance.mlx, instance.win, img, x, y);
	mlx_destroy_image(instance.mlx, img);
}
