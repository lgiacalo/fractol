/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 21:21:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/19 18:50:28 by lgiacalo         ###   ########.fr       */
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

void	*mandelbrot_calcul1(void *mlxx)
{
	int			k;
	int			i;
	t_dcoord	c;
	t_coord		b;
	t_mlx		*mlx;

	mlx = (t_mlx *)mlxx;
	b.y = mlx->win[0].ind;
	k = 0;
	while (b.y < mlx->win[0].max)
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
	mlx->win[0].ind = b.y;
	pthread_exit(NULL);
}

void	mandelbrot(t_mlx *mlx)
{
	int			size;
	int			i;
	pthread_t	tab[4];
	t_mlx		cop[4];

	ft_image(mlx);
	i = -1;
	size = mlx->win[0].size_line;
	while (++i < 4)
	{
		ft_memcpy((void *)(&cop[i]), (void *)mlx, sizeof(t_mlx));
		cop[i].win[0].ind = (XXX / 4) * i;
		cop[i].win[0].max = (XXX / 4) * (i + 1);
		cop[i].win[0].img_str += ((((XXX / 4)) * size) * i);
		pthread_create(&tab[i], NULL, mandelbrot_calcul1, (void *)&(cop[i]));
	}
	pthread_join(tab[0], NULL);
	pthread_join(tab[1], NULL);
	pthread_join(tab[2], NULL);
	pthread_join(tab[3], NULL);
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
