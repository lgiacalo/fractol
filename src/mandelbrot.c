/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:21:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/17 19:08:04 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_mlx *mlx)
{
	t_win	*win;

	win = &mlx->win[0];
	win->p.x = XXX / 2;
	win->p.y = YYY / 2;
	win->zoom = 100;
	win->iter_max = 50;
}

int		mandelbrot_calcul(t_mlx *mlx, t_dcoord c)
{
	int	k = 0;

	double		tmp;
	t_dcoord	z;
	int			i;

	i = -1;
	z.x = 0;
	z.y = 0;
	while (((z.x * z.x) + (z.y * z.y)) < 4 && ++i < mlx->win[k].iter_max)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.y * tmp + c.y;
	}
	return (i);
}

void	mandelbrot(t_mlx *mlx)
{
	int k = 0;

	int			i;
	t_dcoord	c;
	t_coord		b;

	b.x = -1;
	while (++b.x < XXX)
	{
		b.y = -1;
		while (++b.y < XXX)
		{
			c.x = (b.x - mlx->win[k].p.x) / (mlx->win[k].zoom);
			c.y = (b.y - mlx->win[k].p.y) / (mlx->win[k].zoom);
			i = mandelbrot_calcul(mlx, c);
			put_pixel(mlx, b, i);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr, mlx->win[0].img_ptr, 0, 0);
}
