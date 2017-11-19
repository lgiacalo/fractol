/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 21:13:23 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/19 19:17:13 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_thread(t_mlx *mlx, void	*func)
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
		pthread_create(&tab[i], NULL, func, (void *)&(cop[i]));
	}
	pthread_join(tab[0], NULL);
	pthread_join(tab[1], NULL);
	pthread_join(tab[2], NULL);
	pthread_join(tab[3], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr,
			mlx->win[0].img_ptr, 0, 0);
}

void	draw_fractal(t_mlx *mlx)
{
	void	*func;

	func = NULL;
	if (mlx->opt == MANDEL)
		func = mandelbrot;
	else if (mlx->opt == JULIA)
		func = julia;
	else if (mlx->opt == BURN)
		func = burning;
	ft_thread(mlx, func);	
}

int		my_mouse_julia_funct(int x, int y, t_mlx *mlx)
{
	if (mlx->opt == JULIA && x >= 1 && x <= 1000 && y >= 1 && y <= 1000)
	{
		mlx->win[0].c.x = (x / 550.0) - 1;
		mlx->win[0].c.y = (y / 1000.0);
		ft_thread(mlx, julia);
	}
	return (0);
}

void	ft_option_equation(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A)
		mlx->abs = KEY_A;
	else if (keycode == KEY_S)
		mlx->abs = KEY_S;
	else if (keycode == KEY_N2)
		mlx->power = 2;
	else if (keycode == KEY_N3)
		mlx->power = 3;
	else if (keycode == KEY_N4)
		mlx->power = 4;
	else if (keycode == KEY_N5)
		mlx->power = 5;
	else if (keycode == KEY_R)
		init_fractal(mlx);
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
	ft_option_equation(keycode, mlx);
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
