/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:44:33 by rpaulino          #+#    #+#             */
/*   Updated: 2022/04/19 01:36:25 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

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

typedef struct s_light
{
	t_coordinates	coordinates;
	double			brightness_ratio;
	t_color			color;
}		t_light;

typedef struct s_camera
{
	size_t	FOV;
	t_coordinates coordinates;
	t_norm_vector norm_vector;
}		t_camera;


typedef struct s_ambient
{
	double	lighting_ratio;
	t_color	color;
}		t_ambient;

// MULTIPLE ELEMENTS
typedef struct s_plane
{
	t_coordinates coordinates;
	t_norm_vector norm_vector;
	t_color color;
	struct s_plane *next;
}		t_plane;
typedef struct s_cylinder
{
	t_coordinates coordinates;
	t_norm_vector norm_vector;
	t_color color;
	double	diameter;
	double	height;
	struct s_cylinder *next;
}		t_cylinder;

typedef struct s_sphere
{
	t_coordinates	coordinates;
	t_color			color;
	double			diameter;
	struct s_sphere		*next;
}		t_sphere;
//_____________________________
typedef struct s_data
{
	t_light			light;
	t_camera		camera;
	t_ambient		ambient;
	t_plane			*plane;
	t_sphere		*sphere;
	t_cylinder		*cylinder;
}					t_data;

#endif