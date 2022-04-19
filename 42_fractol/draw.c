/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:14:36 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/20 08:09:50 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	set_image(t_draw *image, t_complex_n z)
{
	if (image->set == 'm')
		return (mandelbrot(z, image->max_iterations));
	else if (image->set == 'j')
		return (julia(image->julia, z, image->max_iterations));
	else if (image->set == 't')
		return (tricorn(z, image->max_iterations));
	return (0);
}

void	draw_fractal(t_draw *image)
{
	long double	iterations;
	long double	i;
	long double	j;
	t_complex_n	z;

	i = 0;
	j = 0;
	while (i < image->width)
	{
		z.real = image->re_start + (i / image->width) * image->re_e_minus_s0;
		while (j < image->height)
		{
			z.imag = image->im_start + (j / image->height)
				* image->im_e_minus_s0;
			iterations = set_image(image, z);
			my_mlx_pixel_put(&image->img, i, j, rgb_color(image, iterations));
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr, image->img.img,
		0, 0);
}
