/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:03:27 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/20 11:51:41 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mlx_get_hex_trgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

int	special_colors(t_draw *image, int iterations, int color)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	if (image->mode == 2)
	{
		iterations = (iterations + 1 - (log(log(my_fabs(iterations))
						/ image->max_iterations)));
		r = (int)(255 * iterations / image->max_iterations);
		g = pow(255 / image->max_iterations, 1.5);
		b = (int)(255 * iterations / image->max_iterations);
	}
	if (image->mode == 3)
	{
		if (iterations == image->max_iterations)
			return (mlx_get_hex_trgb(0, 0, 0));
		r = iterations * image->max_iterations / 2;
		g = (image->max_iterations) / 3;
		b = image->max_iterations + color / 4;
	}
	return (mlx_get_hex_trgb(r, g, b));
}

int	rgb_color(t_draw *image, int iterations)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = 0;
	g = 0;
	b = 0;
	color = 255 - (iterations * 255 / image->max_iterations);
	if (image->mode > 1)
		return (special_colors(image, iterations, color));
	if (image->mode == 1)
	{
		r = 255 - color;
		g = 255 - color;
		b = 255 - color;
	}
	else if (image->mode == 0)
	{
		r = color;
		g = color;
		b = color;
	}
	return (mlx_get_hex_trgb(r, g, b));
}
