/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/13 02:55:55 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../minilibx_macos/mlx.h"

# define MANDEL	0
# define JULIA	1

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_win
{
	int			fractol;
	void		*win_ptr;
	void		*img_ptr;
	t_coord		img_len;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*img_str;
}				t_win;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	int			nbr;
	t_win		win[2];
}				t_mlx;

void			ft_usage(void);

#endif
