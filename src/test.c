/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 02:46:38 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/06 13:02:16 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// ESSAI DE FRACTALES DIFFERENTES

void	init_test(t_mlx *mlx)
{
	t_win	*win;

	win = &mlx->win[0];
	win->p.x = 700;
	win->p.y = 500;
	win->zoom = 230;
	win->iter_max = 200;
	win->z.x = 0.0;
	win->z.y = 0.0;
}

int		test_calcul(t_mlx *mlx, t_dcoord c, t_dcoord *pos)
{
	int			k;
	double		tmp;
	t_dcoord	z;
	int			i;

	i = -1;
	z = mlx->win[0].z;
	k = 0;
	while (((z.x * z.x) + (z.y * z.y)) < 4 && ++i < mlx->win[k].iter_max)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.y * tmp + c.y;
		pos[i].x = z.x;
		pos[i].y = z.y;
	}
	return (i);
}

void	test(t_mlx *mlx)
{
	int			k;
	t_dcoord	pos[200];
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
			i = test_calcul(mlx, c, pos);
			if (i != mlx->win[0].iter_max)
			{
				int j = 0;
				while (j < i)
				{
					c.x = 0.3 * XXX * (pos[i].x + 0.5) + XXX / 2;
					c.y = 0.3 * YYY * pos[i].y + YYY / 2;
					if (c.x >= 0 && c.y >= 0 && c.x < XXX && c.y < YYY)
					{
					//	mlx->win[0].img_str[(int)(c.y * mlx->win[0].size_line + c.x)] += 1;
						mlx->win[0].img_str[(int)(b.y * mlx->win[0].size_line + b.x)] += 10;
					}
					j++;
				}
			}
			//			put_pixel(mlx, b, i);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr, mlx->win[0].img_ptr, 0, 0);
}
