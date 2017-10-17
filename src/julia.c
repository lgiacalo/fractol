/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 05:24:22 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/17 20:30:42 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	init_julia(t_mlx *mlx)
{
	t_win	*win;

	win = &mlx->win[0];
	win->p.x = XXX / 2;
	win->p.y = YYY / 2;
	win->zoom= 300;
	win->iter_max = 120;
	win->c.x = 0.285;
	win->c.y = 0.01;
}

void	julia(t_mlx *mlx)
{
	double		tmp;
	t_coord		b;

	b.x = -1;
	while (++b.x < XXX)
	{
		b.y = -1;
		while (++b.y < YYY)
		{
			double	z_r = (b.x - mlx->win[0].p.x) / mlx->win[0].zoom;
			double	z_i = (b.y - mlx->win[0].p.y) / mlx->win[0].zoom;
			int		i = 0;
			while (((z_r * z_r) + (z_i * z_i)) < 4 && i < mlx->win[0].iter_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + mlx->win[0].c.x;
				z_i = 2 * z_i * tmp + mlx->win[0].c.y;
				i++;
			}
			put_pixel(mlx, b, i);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr, mlx->win[0].img_ptr, 0, 0);
}


/*
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
			if (i == iter_max)
				put_pixel(mlx, b, i);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr, mlx->win[0].img_ptr, 0, 0);
}
*/
