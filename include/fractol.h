/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/17 20:29:25 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "../minilibx_macos/mlx.h"

# define MANDEL	0
# define JULIA	1

# define XXX		1000
# define YYY		1000

# define KEY_ESC	53

# define KEY_P		69
# define KEY_M		78

# define KEY_H		126
# define KEY_B		125
# define KEY_D		124
# define KEY_G		123

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_dcoord
{
	double			x;
	double			y;
}					t_dcoord;

typedef struct		s_win
{
	int				fractol;
	void			*win_ptr;
	void			*img_ptr;
	t_coord			img_len;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*img_str;
	t_coord			p;
	double			zoom;
	int				iter_max;
	t_dcoord		c;
}					t_win;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	int				nbr;
	t_win			win[2];
	int				color;
}					t_mlx;

void				ft_usage(void);

void				init_mandelbrot(t_mlx *mlx);
void				mandelbrot(t_mlx *mlx);

void				init_julia(t_mlx *mlx);
void				julia(t_mlx *mlx);

int					my_key_funct(int keycode, t_mlx *mlx);
int					my_mouse_funct(int button, int x, int y, t_mlx *mlx);

void				put_pixel(t_mlx *mlx, t_coord b, int i);

#endif
