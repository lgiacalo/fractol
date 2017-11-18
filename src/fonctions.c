/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 02:33:41 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/18 23:55:16 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_mlx *mlx, t_coord b, int i)
{
	char	*str;
	int		size_line;
	int		color;

	if (b.y >= ((XXX / 4) * 3))
		b.y = b.y - ((XXX / 4) * 3);
	else if (b.y >= ((XXX / 4) * 2))
		b.y = b.y - ((XXX / 4) * 2);
	else if (b.y >= (XXX / 4))
		b.y = b.y - (XXX / 4);
	str = mlx->win[0].img_str;
	size_line = mlx->win[0].size_line;
	color = mlx->color;
	if (i != mlx->win[0].iter_max)
	{
		str[b.x * 4 + b.y * size_line] = (color * i) % 255;
		str[(b.x * 4) + (b.y * size_line) + 1] = 0;
		str[(b.x * 4) + (b.y * size_line) + 2] = 0;
	}
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
