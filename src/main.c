/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:42:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/13 02:55:54 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		my_key_funct(int keycode, t_mlx *mlx)
{
	(void)mlx;
	ft_fdprintf(1, "Valeur de bit_per_pixel = [%d]\n", mlx->win[0].bits_per_pixel);
	ft_fdprintf(1, "Valeur de size_line = [%d]\n", mlx->win[0].size_line);
	ft_fdprintf(1, "Valeur de endian = [%d]\n", mlx->win[0].endian);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	put_pixel(t_mlx *mlx, int x, int y, int i)
{
	char	*str = mlx->win[0].img_str;
	int		size_line = mlx->win[0].size_line;

	if (x < 400 && y < 400)
	{
//		str[x * 4 + y * size_line] = 255 - i * 1;
//		str[x * 4 + y * size_line] = 250 % (i * 2);
		str[x * 4 + y * size_line] = (x % 255) % (i * 2);
//		str[(x * 4) + (y * size_line) + 1] = 255 - (i * 2) - 20;
//		str[(x * 4) + (y * size_line) + 1] = 250 % (i * 3);
		str[(x * 4) + (y * size_line) + 1] = (x % 255) % (i * 3);
//		str[(x * 4) + (y * size_line) + 1] = 255 - (i * 2) - 20;
//		str[(x * 4) + (y * size_line) + 2] = 250 % (i * 4);
		str[(x * 4) + (y * size_line) + 2] = (x % 255) % (i * 4);
	}
}

void	draw_img(t_mlx *mlx)
{
	double	x1 = -2.1;
	double	x2 = 0.6;
	double	y1 = -1.2;
	double	y2 = 1.2;

	int	img_x = 500;
	int	img_y = 500;

	int i_max = 20;

	double zoom_x = img_x / (x2 - x1);
	double zoom_y = img_y / (y2 - y1);

	int	x = 0;
	int y = 0;

	while (x < img_x)
	{
		y = 0;
		while (y < img_y)
		{
			double c_r = x / zoom_x + x1;
			double c_i = y / zoom_y + y1;
			double z_r = 0;
			double z_i = 0;
			int i = 0;

			while ((z_r * z_r + z_i * z_i) < 4 && (i < i_max))
			{
				double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
//			if (i == i_max)
				put_pixel(mlx, x, y, i);
			y++;
		}
		x++;
	}
}

int	ft_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init(0)))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].win_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "Fractol")))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].img_ptr = mlx_new_image(mlx->mlx_ptr, 400, 400)))
		return (EXIT_FAILURE);
	if (!(mlx->win[0].img_str = mlx_get_data_addr(mlx->win[0].img_ptr, &(mlx->win[0].bits_per_pixel),
					&(mlx->win[0].size_line), &(mlx->win[0].endian))))
		return (EXIT_FAILURE);
	draw_img(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win[0].win_ptr, mlx->win[0].img_ptr, 50, 50);
	mlx_key_hook(mlx->win[0].win_ptr, &my_key_funct, mlx);
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
