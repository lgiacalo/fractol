/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:42:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/19 19:33:41 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_image(t_mlx *mlx)
{
	if (mlx->win[0].img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->win[0].img_ptr);
	if (!(mlx->win[0].img_ptr = mlx_new_image(mlx->mlx_ptr, YYY, YYY)))
		exit(0);
	if (!(mlx->win[0].img_str = mlx_get_data_addr(mlx->win[0].img_ptr,
					&(mlx->win[0].bits_per_pixel), &(mlx->win[0].size_line),
					&(mlx->win[0].endian))))
		exit(0);
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

int		ft_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init(0)))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].win_ptr = mlx_new_window(mlx->mlx_ptr,
					XXX, YYY, "Fractol")))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].img_ptr = mlx_new_image(mlx->mlx_ptr, YYY, YYY)))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].img_str = mlx_get_data_addr(mlx->win[0].img_ptr,
					&(mlx->win[0].bits_per_pixel), &(mlx->win[0].size_line),
					&(mlx->win[0].endian))))
		return (EXIT_FAILURE);
	draw_fractal(mlx);
	mlx_key_hook(mlx->win[0].win_ptr, &my_key_funct, mlx);
	mlx_mouse_hook(mlx->win[0].win_ptr, &my_mouse_funct, mlx);
	mlx_hook(mlx->win[0].win_ptr, 6, 0, &my_mouse_julia_funct, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}

void	init_fractal(t_mlx *mlx)
{
	if (mlx->opt == MANDEL)
		init_mandelbrot(mlx);
	else if (mlx->opt == JULIA)
		init_julia(mlx);
	else if (mlx->opt == BURN)
		init_burning(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.opt = 0;
	mlx.color = 50;
	mlx.abs = KEY_S;
	mlx.power = 2;
	mlx.win[0].img_ptr = NULL;
	if (argc < 2 || argc > 3 || !(mlx.opt = reading_choice(argv, argc)))
		ft_usage();
	ft_usage_clavier();
	init_fractal(&mlx);
	ft_init(&mlx);
	return (0);
}
