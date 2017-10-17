/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 05:24:22 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/17 05:54:54 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
   void	init_julia(t_mlx *mlx)
   {

   }
   */

void	julia(t_mlx *mlx)
{
	double		tmp;
	t_coord		b;

	double	x1 = -1;
	double	x2 = 1;

	double	y1 = -1.2;
	double	y2 = 1.2;

	double	zoom = 100;
	int		iter_max = 150;

	int img_x = (x2 - x1) * zoom;
	int	img_y = (y2 - y1) * zoom;

	b.x = -1;
	while (++b.x < img_x)
	{
		b.y = -1;
		while (++b.y < img_y)
		{
			double	c_r = 0.285;
			double	c_i = 0.01;

			double	z_r = (b.x) / zoom + x1;
			double	z_i = (b.y) / zoom + y1;
			int		i = 0;
			while (((z_r * z_r) + (z_i * z_i)) < 4 && i < iter_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			put_pixel(mlx, b, i);
		}
	}
}
