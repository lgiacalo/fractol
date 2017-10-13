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

int		main(int argc, char **argv)
{
	int	fractal;

	if (argc < 2 || argc > 3)
		ft_usage();
	ft_fdprintf(1, "Debut Fractol !!\n\n");
	if (ft_strequ("Mandelbrot", argv[1]))
		fractal = 0;
	else if (ft_strequ("Julia", argv[1]))
		fractal = 1;
	else
		ft_usage();

//	ft_init()
	return (0);
}
