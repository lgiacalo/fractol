/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:28:01 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/18 20:29:01 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_usage_clavier(void)
{
	ft_fdprintf(1, "\nUsage Clavier : \n");
	ft_fdprintf(1, "\t - A/S : avec ou sans valeur absolue\n");
	ft_fdprintf(1, "\t - C : changement couleur\n");
	ft_fdprintf(1, "\t - +/- : plus ou moins d'iteration\n");
	ft_fdprintf(1, "\t - Fleches  : mouvement fractal\n\n");
	ft_fdprintf(1, "Pad Numerique : \n");
	ft_fdprintf(1, "\t - 2/3/4/5 : changement puissance fractal\n");
	ft_fdprintf(1, "\t - +/- : zoom (ou avec la souris)\n");
	ft_fdprintf(1, "- ESC : Sortie\n\n");
}

void	ft_usage(void)
{
	ft_fdprintf(1, "\nUsage: ./fractol <filename>\n");
	ft_fdprintf(1, "- Julia\n");
	ft_fdprintf(1, "- Burning\n");
	ft_fdprintf(1, "- Mandelbrot\n");
	exit(0);
}
