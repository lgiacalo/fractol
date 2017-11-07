/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 02:33:41 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/07 01:43:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h> //

void	put_pixel(t_mlx *mlx, t_coord b, int i)
{
	char	*str = mlx->win[0].img_str;
	int		size_line = mlx->win[0].size_line;
	int		color = mlx->color;
	(void)i;

	if (i != mlx->win[0].iter_max)
	{
		str[b.x * 4 + b.y * size_line] = (color * i) % 255;
		str[(b.x * 4) + (b.y * size_line) + 1] = 0;
		str[(b.x * 4) + (b.y * size_line) + 2] = 0;
	}
	else
	{
		str[b.x * 4 + b.y * size_line] = ((b.y + color)) % 255;
		str[(b.x * 4) + (b.y * size_line) + 1] = (b.x * (b.y + color)) % 255;
		str[(b.x * 4) + (b.y * size_line) + 2] = ((b.x + color)) % 255;
	}

}

void	draw_fractal(t_mlx *mlx)
{
	if (mlx->opt == MANDEL)
		mandelbrot(mlx);
	else if (mlx->opt == JULIA)
		julia(mlx);
	else if (mlx->opt == BURN)
		burning(mlx);
	else if (mlx->opt == TEST)
		test(mlx);
}

double	ft_abs(double x)
{
	return ((x > 0) ? x : (x * -1.0));
}

void	ft_abs_dcoord(t_dcoord *z)
{
	if (!z)
		return ;
	z->x = ft_abs(z->x);
	z->y = ft_abs(z->y);
}

void	ft_usage(void)
{
	ft_fdprintf(1, "\nUsage: ./fractol <filename>\n");
	ft_fdprintf(1, "- Julia\n");
	ft_fdprintf(1, "- Mandelbrot\n");
	ft_fdprintf(1, "(Max 2 arguments !!)\n\n");
	exit(0);
}
