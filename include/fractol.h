/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/11/19 18:44:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "clavier.h"
# include "../minilibx_macos/mlx.h"
# include <pthread.h>

# define MANDEL	(1 << 0)
# define JULIA	(1 << 1)
# define BURN	(1 << 2)
# define TEST	(1 << 3)

# define XXX		1000
# define YYY		1000

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
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*win_ptr;
	void			*img_ptr;
	double			zoom;
	t_coord			img_len;
	char			*img_str;
	t_coord			p;
	t_dcoord		z;
	t_dcoord		c;
	int				iter_max;
	int				ind;
	int				max;
}					t_win;

typedef struct		s_mlx
{
	int				opt;
	int				nbr;
	void			*mlx_ptr;
	t_win			win[2];
	int				color;
	int				abs;
	int				power;
}					t_mlx;

void				ft_usage(void);
void				ft_usage_clavier(void);
double				ft_abs(double x);
void				ft_abs_dcoord(t_dcoord *z);
t_mlx				ft_copy(t_mlx mlx);

void				draw_fractal(t_mlx *mlx);
void				ft_mandelbrot_power(t_dcoord *z, t_dcoord c, int power);
void				ft_image(t_mlx *mlx);

void				init_fractal(t_mlx *mlx);
void				init_mandelbrot(t_mlx *mlx);
void				init_julia(t_mlx *mlx);
void				init_burning(t_mlx *mlx);
void				mandelbrot(t_mlx *mlx);
void				julia(t_mlx *mlx);
void				burning(t_mlx *mlx);

int					my_key_funct(int keycode, t_mlx *mlx);
int					my_mouse_funct(int button, int x, int y, t_mlx *mlx);
int					my_mouse_julia_funct(int x, int y, t_mlx *mlx);

void				put_pixel(t_mlx *mlx, t_coord b, int i);

#endif
