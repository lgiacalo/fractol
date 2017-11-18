/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:21:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/18 23:54:52 by lgiacalo         ###   ########.fr       */
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

	i = -1;
	z = mlx->win[0].z;
	k = 0;
	while (((z.x * z.x) + (z.y * z.y)) < 4 && ++i < mlx->win[k].iter_max)
		ft_mandelbrot_power(&z, c, mlx->power);
	return (i);
}

void	mandelbrot_calcul1(t_mlx *mlx, int *x, int max)
{
	int			k;
	int			i;
	t_dcoord	c;
	t_coord		b;

	b.y = *x;
	k = 0;
	while (b.y < max)
	{
		b.x = 0;
		while (b.x < XXX)
		{
			c.x = (b.x - mlx->win[k].p.x) / (mlx->win[k].zoom);
			c.y = (b.y - mlx->win[k].p.y) / (mlx->win[k].zoom);
			i = mandelbrot_calcul(mlx, c);
			if (i != mlx->win[k].iter_max)
				put_pixel(mlx, b, i);
			b.x++;
		}
		b.y++;
	}
	*x = b.y;
}

void	mandelbrot(t_mlx *mlx)
{
	int	x;
	int	max;
	int	size;

	ft_image(mlx);
	size = mlx->win[0].size_line;

	x = 0;
	max = XXX/4;
	mandelbrot_calcul1(mlx, &x, max);

	max = (XXX / 4) * 2;
	mlx->win[0].img_str += (((XXX / 4)) * size);
	mandelbrot_calcul1(mlx, &x, max);

	max = (XXX / 4) * 3;
	mlx->win[0].img_str += (((XXX / 4)) * size);
	mandelbrot_calcul1(mlx, &x, max);

	max = XXX;
	mlx->win[0].img_str += (((XXX / 4)) * size);
	mandelbrot_calcul1(mlx, &x, XXX);

	mlx->win[0].img_str -= XXX * size;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr,
			mlx->win[0].img_ptr, 0, 0);
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
