/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:44:12 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/05/10 22:14:42 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_put_img(t_mlx_instance instance, char *file, int *location)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(instance.mlx, file, &width, &height);
	if (!img)
		ft_error();
	mlx_put_image_to_window\
	(instance.mlx, instance.win, img, location[0], location[1]);
	mlx_destroy_image(instance.mlx, img);
}
