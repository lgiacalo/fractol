/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:24:45 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/06 01:01:39 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia3(t_mlx *mlx)
{
	t_win	*win;

	win = &mlx->win[0];
	win->p.x = XXX / 2;
	win->p.y = YYY / 2;
	win->zoom= 250;
	win->iter_max = 120;
	win->z.x = 0.0;
	win->z.y = 0.0;
	win->c.x = -0.026667;
	win->c.y = 0.772000;
}

void	julia3(t_mlx *mlx)
{
	double		tmp;
	t_dcoord	z;
	t_coord		b;
	int			i;

	b.x = -1;
	while (++b.x < XXX)
	{
		b.y = -1;
		while (++b.y < YYY)
		{
			z.x = (b.x - mlx->win[0].p.x) / mlx->win[0].zoom;
			z.y = (b.y - mlx->win[0].p.y) / mlx->win[0].zoom;
			i = -1;
			while (((z.x * z.x) + (z.y * z.y)) < 4 && ++i < mlx->win[0].iter_max)
			{
				tmp = z.x;
				z.x = (tmp * tmp * tmp) - (3 * tmp * z.y * z.y) + mlx->win[0].c.x;
				z.y = (3 * tmp * tmp * z.y) - (z.y * z.y * z.y) + mlx->win[0].c.y;
			}
			put_pixel(mlx, b, i);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr, mlx->win[0].img_ptr, 0, 0);
}
