/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:42:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/05 19:50:46 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init(0)))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].win_ptr = mlx_new_window(mlx->mlx_ptr, XXX, YYY, "Fractol")))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].img_ptr = mlx_new_image(mlx->mlx_ptr, YYY, YYY)))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].img_str = mlx_get_data_addr(mlx->win[0].img_ptr, &(mlx->win[0].bits_per_pixel),
					&(mlx->win[0].size_line), &(mlx->win[0].endian))))
		return (EXIT_FAILURE);
	draw_fractal(mlx);
	mlx_key_hook(mlx->win[0].win_ptr, &my_key_funct, mlx);
	mlx_mouse_hook(mlx->win[0].win_ptr, &my_mouse_funct, mlx);
	mlx_hook(mlx->win[0].win_ptr, 6, 0, &my_mouse_julia_funct, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}

int		reading_choice(char **argv, int argc)
{
	int	opt;

	(void)argc;
	opt = 0;
	if (ft_strchr("Mm", *argv[1]) && ft_strequ("andelbrot", (argv[1] + 1)))
		opt += MANDEL;
	else if(ft_strchr("Jj", *argv[1]) && ft_strequ("ulia", (argv[1] + 1)))
		opt += JULIA;
	else if(ft_strchr("Bb", *argv[1]) && ft_strequ("urning", (argv[1] + 1)))
		opt += BURN; 
	return (opt);
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
	if (argc < 2 || argc > 3 || !(mlx.opt = reading_choice(argv, argc)))
		ft_usage();

	init_fractal(&mlx);
	ft_init(&mlx);
	return (0);
}
