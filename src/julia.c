/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 05:24:22 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/19 19:13:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_mlx *mlx)
{
	t_win	*win;

	win = &mlx->win[0];
	win->p.x = XXX / 2;
	win->p.y = YYY / 2;
	win->zoom = 300;
	win->iter_max = 120;
	win->z.x = 0.0;
	win->z.y = 0.0;
	win->c.x = 0.323636;
	win->c.y = 0.047000;
}

void	*julia(void *mlxx)
{
	t_dcoord	z;
	t_coord		b;
	int			i;
	t_mlx		*mlx;

	mlx = (t_mlx *)mlxx;
	b.y = mlx->win[0].ind - 1;
	while (++b.y < mlx->win[0].max)
	{
		b.x = -1;
		while (++b.x < XXX)
		{
			z.x = (b.x - mlx->win[0].p.x) / mlx->win[0].zoom;
			z.y = (b.y - mlx->win[0].p.y) / mlx->win[0].zoom;
			i = -1;
			while ((z.x * z.x + z.y * z.y) < 4 && ++i < mlx->win[0].iter_max)
			{
				if (mlx->abs == KEY_A)
					ft_abs_dcoord(&z);
				ft_mandelbrot_power(&z, mlx->win[0].c, mlx->power);
			}
			put_pixel(mlx, b, i);
		}
	}
	pthread_exit(NULL);
}
