/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:42:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/17 19:03:45 by lgiacalo         ###   ########.fr       */
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
//	mandelbrot(mlx);
	julia(mlx);
	mlx_key_hook(mlx->win[0].win_ptr, &my_key_funct, mlx);
	mlx_mouse_hook(mlx->win[0].win_ptr, &my_mouse_funct, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argv;
	if (argc < 2 || argc > 3)
		ft_usage();
	ft_fdprintf(1, "Debut Fractol !!\n\n");
//	init_mandelbrot(&mlx);
	init_julia(&mlx);
	mlx.color = 1;
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
