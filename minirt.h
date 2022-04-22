/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:44:33 by rpaulino          #+#    #+#             */
/*   Updated: 2022/04/22 01:32:08 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

# include <string.h> //illegal

//_____________________________
typedef struct s_data
{
	char				*type;
	double				*coordinates;
	double				*norm_vector;
	double				brightness_lighting_ratio;
	double				diameter;
	double				height;
	int					*color;
	int					FOV;
}					t_data;

int		until_another_space(char *string);
void	*parse_one_number(char *string, int is_double);
void	*parse_three_numbers(char *string, int is_double);

#endif