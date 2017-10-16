/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 02:33:41 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/17 01:09:16 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_mlx *mlx, int x, int y, int i)
{
	char	*str = mlx->win[0].img_str;
	int		size_line = mlx->win[0].size_line;

	if (x < XXX && y < YYY)
	{
		str[x * 4 + y * size_line] = i * 255 / 100;
		str[(x * 4) + (y * size_line) + 1] = i * 200 / 100;
		str[(x * 4) + (y * size_line) + 2] = i * 150 / 100;
	}
}

void	ft_usage(void)
{
	ft_fdprintf(1, "\nUsage: ./fractol <filename>\n");
	ft_fdprintf(1, "- Julia\n");
	ft_fdprintf(1, "- Mandelbrot\n");
	ft_fdprintf(1, "(Max 2 arguments !!)\n\n");
	exit(0);
}
