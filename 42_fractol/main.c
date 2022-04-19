/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:44:17 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/29 09:39:18 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_draw *image)
{
	mlx_destroy_image(image->mlx_ptr, image->img.img);
	mlx_destroy_window(image->mlx_ptr, image->win_ptr);
	exit(0);
}

void	fractol(t_draw image)
{
	image.mlx_ptr = mlx_init();
	image.win_ptr = mlx_new_window(image.mlx_ptr,
			image.width, image.height, "Fract'ol");
	image.img.img = mlx_new_image(image.mlx_ptr, image.width, image.height);
	image.img.addr = mlx_get_data_addr(image.img.img, &image.img.bits_per_pixel,
			&image.img.line_length, &image.img.endian);
	draw_fractal(&image);
	mlx_hook(image.win_ptr, 33, 1L << 17, close_window, &image);
	mlx_key_hook(image.win_ptr, key_control, &image);
	mlx_mouse_hook (image.win_ptr, mouse_control, &image);
	mlx_loop(image.mlx_ptr);
}

int	ft_error(void)
{
	printf("Parameter unknown. Try \"mandelbrot\", \"julia r i\" or \"tricorn\".");
	return (0);
}

void	invalid_input(char *argv[])
{
	char	*argtext;
	int		i;

	i = 3;
	argtext = argv[2];
	while (i < 4)
	{
		while (*argtext)
		{
			if (!ft_isdigit(*argtext) && *argtext != '-'
				&& *argtext != '.' && *argtext != ' '
				&& *argtext != '+')
			{
				ft_error();
				exit(0);
			}
			argtext++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_draw	image;

	if (argc < 2 || argc > 4)
		return (ft_error());
	if (ft_strcmp("mandelbrot", argv[1]))
		init_mandelbrot(&image);
	else if (ft_strcmp("julia", argv[1]))
	{
		if (!argv[2] || !argv[3])
			return (ft_error());
		invalid_input(argv);
		init_julia_complex(&image, argv);
	}
	else if (ft_strcmp("tricorn", argv[1]))
		init_tricorn(&image);
	else
		return (ft_error());
	fractol(image);
	return (0);
}
