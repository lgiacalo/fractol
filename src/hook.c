/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 21:13:23 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/05 19:50:43 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	my_mouse_julia_funct(int x, int y, t_mlx *mlx)
{
	if (mlx->opt == JULIA && x >= 1 && x <= 1000 && y >= 1 && y <= 1000)
	{
		mlx->win[0].c.x = (x / 650.0) - 1;
		mlx->win[0].c.y = (y/ 1000.0);
		julia(mlx);
	}
	return (0);
}

int		my_key_funct(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_NPLUS)
		my_mouse_funct(1, 500, 500, mlx);
	else if (keycode == KEY_NMOINS)
		my_mouse_funct(2, 500, 500, mlx);
	else if (keycode == KEY_C)
		mlx->color += 20;
	else if (keycode == KEY_PLUS)
		mlx->win[0].iter_max += 2;
	else if (keycode == KEY_MOINS)
		mlx->win[0].iter_max -= 2;
	else if (keycode == KEY_HAUT)
		mlx->win[0].p.y -= 50;
	else if (keycode == KEY_BAS)
		mlx->win[0].p.y += 50;
	else if (keycode == KEY_GAUCHE)
		mlx->win[0].p.x -= 50;
	else if (keycode == KEY_DROITE)
		mlx->win[0].p.x += 50;
	draw_fractal(mlx);
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_mlx *mlx)
{
	t_win	*win;

	win = &mlx->win[0];
	if (button == 1 || button == 5)
	{
		win->zoom *= 1.2;
		win->iter_max += (mlx->opt == BURN) ? 1 : 2;
		win->p.x -= (x - win->p.x) * 1.2 - (x - win->p.x);
		win->p.y += (win->p.y - y) * 1.2 - (win->p.y - y);
	}
	else if (button == 2 || button == 4)
	{
		win->zoom /= 1.2;
		win->iter_max -= (mlx->opt == BURN) ? 1 : 2;
		win->p.x -= (x - win->p.x) / 1.2 - (x - win->p.x);
		win->p.y += (win->p.y - y) / 1.2 - (win->p.y - y);
	}
	draw_fractal(mlx);
	return (0);
}
