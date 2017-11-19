/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:21:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/19 19:45:07 by lgiacalo         ###   ########.fr       */
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
	int			k;
	t_dcoord	z;
	int			i;
	int			max;

	i = -1;
	z = mlx->win[0].z;
	k = 0;
	max = mlx->win[k].iter_max;
	while (((z.x * z.x) + (z.y * z.y)) < 4 && ++i < max)
		ft_mandelbrot_power(&z, c, mlx->power);
	return (i);
}

void	*mandelbrot(void *mlxx)
{
	int			i;
	t_dcoord	c;
	t_coord		b;
	t_mlx		*mlx;

	mlx = (t_mlx *)mlxx;
	b.y = mlx->win[0].ind - 1;
	while (++b.y < mlx->win[0].max)
	{
		b.x = -1;
		while (++b.x < XXX)
		{
			c.x = (b.x - mlx->win[0].p.x) / (mlx->win[0].zoom);
			c.y = (b.y - mlx->win[0].p.y) / (mlx->win[0].zoom);
			i = mandelbrot_calcul(mlx, c);
			if (i != mlx->win[0].iter_max)
				put_pixel(mlx, b, i);
		}
	}
	mlx->win[0].ind = b.y;
	pthread_exit(NULL);
}

void	ft_mandelbrot_power(t_dcoord *z, t_dcoord c, int power)
{
	double	t;

	t = z->x;
	if (power == 2 || power == 3)
	{
		z->x = (power == 2) ? t * t - z->y * z->y + c.x\
			: (t * t * t) - (3 * t * z->y * z->y) + c.x;
		z->y = (power == 2) ? 2 * z->y * t + c.y\
			: (3 * t * t * z->y) - (z->y * z->y * z->y) + c.y;
	}
	else if (power == 4)
	{
		z->x = (t * t * t * t) - (6 * t * t * z->y * z->y)\
			+ (z->y * z->y * z->y * z->y) + c.x;
		z->y = (4 * t * t * t * z->y) - (4 * t * z->y * z->y * z->y) + c.y;
	}
	else if (power == 5)
	{
		z->x = (t * t * t * t * t) - (10 * t * t * t * z->y * z->y)\
			+ (5 * t * z->y * z->y * z->y * z->y) + c.x;
		z->y = (5 * t * t * t * t * z->y) - (10 * t * t * z->y * z->y * z->y)\
			+ (z->y * z->y * z->y * z->y * z->y) + c.y;
	}
}
