/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:44:12 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/09 20:59:31 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_put_img(t_mlx_instance instance, char *file, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(instance.mlx, file, &width, &height);
	if (!img)
		ft_error();
	mlx_put_image_to_window(instance.mlx, instance.win, img, x, y);
	mlx_destroy_image(instance.mlx, img);
}
