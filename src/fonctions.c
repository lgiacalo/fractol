/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 02:33:41 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/06 22:25:08 by lgiacalo         ###   ########.fr       */
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
	else if (mlx->opt == JULIA3)
		julia3(mlx);
	else if (mlx->opt == JULIA4)
		julia4(mlx);
	else if (mlx->opt == BURN)
		burning(mlx);
	else if (mlx->opt == BURN3)
		burning3(mlx);
	else if (mlx->opt == TEST)
		test(mlx);
}

double	ft_abs(double x)
{
	return ((x > 0) ? x : (x * -1.0));
}

long int	ft_factoriel(int nb)
{
	long int	resultat;
	int			i;

	if (nb == 0)
		return (0);
	i = 0;
	resultat = 1;
	while (++i <= nb)
		resultat *= i;
	return (resultat);
}

double	ft_dpower(double nb, int power)
{
	double resultat;

	resultat = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	resultat = ft_dpower(nb, power - 1) * nb;
	return (resultat);
}

int		ft_triangle_pascal(int k, int n)
{
	int	resultat;

	resultat = ((ft_factoriel(k)) * (ft_factoriel(n - k)));
	if (resultat == 0)
		return (1);
	resultat = ft_factoriel(n) / resultat;
	return (resultat);
}

void	ft_complex_power(t_dcoord *z, t_dcoord c, int power)
{
	int		kr;
	int		ki;
	double	tmp;

	kr = 2;
	tmp = z->x;
	z->x = ft_dpower(tmp, power);
	while (kr <= power)
	{
		if (kr % 4)
			z->x +=  1.00 * (ft_triangle_pascal(kr, power) * (ft_dpower(tmp, (power - kr))) * (ft_dpower(z->y, kr)));
		else
			z->x -= 1.00 * (ft_triangle_pascal(kr, power) * (ft_dpower(tmp, (power - kr))) * (ft_dpower(z->y, kr)));
		kr += 2;
	}
	z->x += c.x;
	ki = 1;
	while (ki <= power)
	{
		if (kr % 6)
			z->y -= ft_triangle_pascal(ki, power) * ft_dpower(tmp, (power - ki)) * ft_dpower(z->y, ki);
		else
			z->y += ft_triangle_pascal(ki, power) * ft_dpower(tmp, (power - ki)) * ft_dpower(z->y, ki);
		ki += 2;
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
