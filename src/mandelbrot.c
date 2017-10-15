/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:21:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/15 03:48:17 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_mlx *mlx, int x, int y, int i)
{
	char	*str = mlx->win[0].img_str;
	int		size_line = mlx->win[0].size_line;

	if (x < XXX && y < YYY)
	{
		str[x * 4 + y * size_line] = i * 255 / 100;
		str[(x * 4) + (y * size_line) + 1] = i * 200 / 100;
		str[(x * 4) + (y * size_line) + 2] = i * 150 / 100;
	}
}

void	mandelbrot(t_mlx *mlx)
{
//	double	x1 = -2.1;
	double	x1 = 0;
//	double	x2 = 0.6;
//	double	y1 = -1.2;
	double	y1 = 0;
//	double	y2 = 1.2;

	int		i_max = mlx->win[0].iter_max;
	double	zoom = mlx->win[0].zoom	;

//	int	img_x = (x2 - x1) * zoom;
//	int	img_y = (y2 - y1) * zoom;
	int	img_x = XXX;
	int	img_y = YYY;

	int	x = 0;
	int y = 0;

	while (x < img_x)
	{
		y = 0;
		while (y < img_y)
		{
			double c_r = x / zoom + x1;
			double c_i = y / zoom + y1;
			double z_r = 0;
			double z_i = 0;
			int i = 0;

			while ((z_r * z_r + z_i * z_i) < 4 && (i < i_max))
			{
				double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			put_pixel(mlx, x, y, i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr, mlx->win[0].img_ptr, 0, 0);
}
