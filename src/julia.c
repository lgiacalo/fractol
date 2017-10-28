/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 05:24:22 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/28 23:06:24 by lgiacalo         ###   ########.fr       */
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
	win->c.x = 0.0;
	win->c.y = 0.5;
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
