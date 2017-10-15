/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:42:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/15 03:43:09 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
			mlx->win[0].zoom += 20;
			mlx->win[0].iter_max += 4;
		}
		else
		{
			mlx->win[0].zoom -= 20;
			mlx->win[0].iter_max -= 4;
		}
		mandelbrot(mlx);
	}
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_mlx *mlx)
{
	(void)mlx;
	ft_fdprintf(1, "Mouse but[%d]-x[%d]-y[%d]\n", button, x, y);
	return (0);
}

int	ft_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init(0)))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "Fractol")))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000)))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].img_str = mlx_get_data_addr(mlx->win[0].img_ptr, &(mlx->win[0].bits_per_pixel),
					&(mlx->win[0].size_line), &(mlx->win[0].endian))))
		return (EXIT_FAILURE);
	mandelbrot(mlx);
	mlx_key_hook(mlx->win[0].win_ptr, &my_key_funct, mlx);
	mlx_mouse_hook(mlx->win[0].win_ptr, &my_mouse_funct, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argv;
	mlx.win[0].zoom = 100;
	mlx.win[0].iter_max = 50;
	if (argc < 2 || argc > 3)
		ft_usage();
	ft_fdprintf(1, "Debut Fractol !!\n\n");
	ft_init(&mlx);
	return (0);
}

/*
   int	fractal;
   if (ft_strequ("Mandelbrot", argv[1]))
   fractal = 0;
   else if (ft_strequ("Julia", argv[1]))
   fractal = 1;
   else
   ft_usage();

//	ft_init()
return (0);
}
*/
