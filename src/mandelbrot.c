/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:21:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/06 22:17:59 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_mlx *mlx)
{
	t_win	*win;

	win = &mlx->win[0];
	win->p.x = 700;
	win->p.y = 500;
	win->zoom = 330;
	win->iter_max = 60;
	win->z.x = 0.0;
	win->z.y = 0.0;
}

int		mandelbrot_calcul(t_mlx *mlx, t_dcoord c)
{
	int			k;;
	double		tmp;
	t_dcoord	z;
	int			i;

	i = -1;
	z = mlx->win[0].z;
	k = 0;
	while (((z.x * z.x) + (z.y * z.y)) < 4 && ++i < mlx->win[k].iter_max)
	{
		tmp = z.x;
//		z.x = z.x * z.x - z.y * z.y + c.x;
//		z.y = 2 * z.y * tmp + c.y;
		ft_complex_power(&z, c, 2);
	}
	return (i);
}

void	mandelbrot(t_mlx *mlx)
{
	int			k;
	int			i;
	t_dcoord	c;
	t_coord		b;

	b.x = -1;
	k = 0;
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
