/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 21:13:23 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/17 05:23:57 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h> ///////////////

int		my_key_funct(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == KEY_ESC)
	{
		ft_fdprintf(1, "Valeur de bit_per_pixel = [%d]\n", mlx->win[0].bits_per_pixel);
		ft_fdprintf(1, "Valeur de size_line = [%d]\n", mlx->win[0].size_line);
		ft_fdprintf(1, "Valeur de endian = [%d]\n", mlx->win[0].endian);
		exit(0);
	}
	if (keycode == KEY_P || keycode == KEY_M)
	{
		if (keycode == KEY_P)
		{
			mlx->win[0].zoom *= 1.5;
			mlx->win[0].iter_max += 2;
		}
		else
		{
			mlx->win[0].zoom /= 1.5;
			mlx->win[0].iter_max -= 2;
		}
		printf("Zoom = [%lf]\n", mlx->win[0].zoom);
		ft_fdprintf(1, "iter_max = [%d]\n", mlx->win[0].iter_max);
		mandelbrot(mlx);
	}
	if (keycode == 8)
		mlx->color += 10;
	if (keycode == KEY_H)
		mlx->win[0].p.y -= 50;
	else if (keycode == KEY_B)
		mlx->win[0].p.y += 50;
	else if (keycode == KEY_G)
		mlx->win[0].p.x -= 50;
	else if (keycode == KEY_D)
		mlx->win[0].p.x += 50;
	ft_fdprintf(1, "x1[%d]--y1[%d]\n", mlx->win[0].p.x, mlx->win[0].p.y);
	mandelbrot(mlx);
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_mlx *mlx)
{
	double tmp;

	ft_fdprintf(1, "Mouse but[%d]-x[%d]-y[%d]\n", button, x, y);
	if (button == 1)
	{
		mlx->win[0].zoom *= 1.2;
		mlx->win[0].iter_max += 2;
		tmp = mlx->win[0].p.x;
		mlx->win[0].p.x -= (x - tmp) * 1.2 - (x - tmp);
		tmp = mlx->win[0].p.y;
		mlx->win[0].p.y += (tmp - y) * 1.2 - (tmp - y);
		ft_fdprintf(1, "x1[%d]--y1[%d]\n", mlx->win[0].p.x, mlx->win[0].p.y);
	}
	else if (button == 2)
	{
		mlx->win[0].zoom /= 1.2;
		mlx->win[0].iter_max -= 2;
		tmp = mlx->win[0].p.x;
		mlx->win[0].p.x -= (x - tmp) / 1.2 - (x - tmp);
		tmp = mlx->win[0].p.y;
		mlx->win[0].p.y += (tmp - y) / 1.2 - (tmp - y);
		ft_fdprintf(1, "x1[%d]--y1[%d]\n", mlx->win[0].p.x, mlx->win[0].p.y);
	}
	mandelbrot(mlx);
	return (0);
}
