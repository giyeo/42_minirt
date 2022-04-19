/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:44:33 by rpaulino          #+#    #+#             */
/*   Updated: 2022/04/19 00:59:37 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <errno.h>
#include <stdlib.h>

typedef struct s_coordinates
{
	double x;
	double y;
	double z;
}		t_coordinates;

typedef struct s_norm_vector 
{
	double x;
	double y;
	double z;
}		t_norm_vector;

typedef struct s_color
{
	size_t x;
	size_t y;
	size_t z;
}		t_color;

typedef struct s_cylinder
{
	double	diameter;
	double	height;
}		t_cylinder;

typedef struct s_sphere
{
	double	diameter;
}		t_sphere;

typedef struct s_light
{
	double	 brightness_ratio;
}		t_light;

typedef struct s_camera
{
	size_t	FOV;
}		t_camera;

typedef struct s_ambient
{
	double	lighting_ratio;
}		t_ambient;

typedef struct s_entity
{
	char			*identifier;
	t_coordinates	coordinates;
	t_color			color;
	t_norm_vector	norm_vector;
	t_light			light;
	t_camera		camera;
	t_ambient		ambient;
	t_sphere		sphere;
	t_cylinder		cylinder;
	struct s_entity	*next;
}					t_entity;

#endif