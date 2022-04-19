/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:52:44 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/17 15:52:44 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define KEY_UP 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define ESC 65307

typedef struct t_direct
{
	int			left;
	int			right;
	int			up;
	int			down;
	long double	pctnx;
	long double	pctny;
}	t_direction;

typedef struct t_complex_num
{
	long double	real;
	long double	imag;
}	t_complex_n;

typedef struct store_cord
{
	long double	xmin;
	long double	xmax;
	long double	ymin;
	long double	ymax;
}	t_store_xy;

typedef struct pxy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct re_draw
{
	void		*mlx_ptr;
	void		*win_ptr;
	long double	re_start;
	long double	re_end;
	long double	im_start;
	long double	im_end;
	long double	zoom;
	int			width;
	int			height;
	int			max_iterations;
	char		set;
	t_xy		m3;
	t_data		img;
	t_complex_n	julia;
	int			mode;
	long double	re_e_minus_s0;
	long double	im_e_minus_s0;
}	t_draw;

/*Set Related					*/
void		init_mandelbrot(t_draw *image);
void		init_julia(t_draw *image);
void		init_tricorn(t_draw *image);
void		init_julia_complex(t_draw *image, char *argv[]);
int			mandelbrot(t_complex_n c, int max_iterations);
int			julia(t_complex_n c, t_complex_n z, int max_iterations);
int			tricorn(t_complex_n c, int max_iterations);

/*Color Related					*/
int			mlx_get_hex_trgb(int r, int g, int b);
int			rgb_color(t_draw *image, int iterations);

/*Control Related				*/
int			key_control(int k, t_draw *image);
int			mouse_control(int button, int x, int y, t_draw *image);
int			close_window(t_draw *image);

/*Draw Related					*/
void		draw_fractal(t_draw *image);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*ZOOM Related					*/
void		zoom_in(t_draw *image);
void		zoom_out(t_draw *image);

/*UTILS Related					*/
long double	my_fabs(long double number);
int			ft_strcmp(const char *str1, const char *str2);
double		my_atof(char *number);
int			ft_isspace(int argument);
int			ft_isdigit(int argument);

#endif
