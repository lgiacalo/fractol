/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:52:19 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/19 19:13:02 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_burning(t_mlx *mlx)
{
	t_win	*win;

	win = &mlx->win[0];
	win->p.x = 566;
	win->p.y = 483;
	win->zoom = 275;
	win->iter_max = 40;
	win->z.x = 0.0;
	win->z.y = 0.0;
}

int		burning_calcul(t_mlx *mlx, t_dcoord c)
{
	int			k;
	t_dcoord	z;
	int			i;

	i = -1;
	z = mlx->win[0].z;
	k = 0;
	while (((z.x * z.x) + (z.y * z.y)) < 4 && ++i < mlx->win[k].iter_max)
	{
		ft_abs_dcoord(&z);
		ft_mandelbrot_power(&z, c, mlx->power);
	}
	return (i);
}

void	*burning(void *mlxx)
{
	int			k;
	int			i;
	t_dcoord	c;
	t_coord		b;
	t_mlx		*mlx;

	mlx = (t_mlx *)mlxx;
	b.y = mlx->win[0].ind - 1;
	k = 0;
	while (++b.y < mlx->win[0].max)
	{
		b.x = -1;
		while (++b.x < XXX)
		{
			c.x = ((b.x - mlx->win[k].p.x) / (mlx->win[k].zoom));
			c.y = ((b.y - mlx->win[k].p.y) / (mlx->win[k].zoom));
			i = burning_calcul(mlx, c);
			put_pixel(mlx, b, i);
		}
	}
	pthread_exit(NULL);
}
