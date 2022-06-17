/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:44:36 by rpaulino          #+#    #+#             */
/*   Updated: 2022/04/18 23:44:36 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_data(t_data *data)
{
	data->brightness_lighting_ratio = 0;
	data->diameter = 0;
	data->height = 0;
	data->FOV = 0;
	data->type = NULL;
	data->coordinates = NULL;
	data->norm_vector = NULL;
	data->color = NULL;
}

char *raw_data[] =
{"A 0.2 255,255,255"
,"C -50,0,20 0,0,0 70"
,"L -40,0,30 0.7 255,255,255"
,"pl 0,0,0 0,1.0,0 255,0,225"
,"sp 0,0,20 20 255,0,0"
,"cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255"};

int main(void)
{
	t_data *arguments;
	int raw_data_size;
	int i;

	raw_data_size = sizeof(raw_data) / 8;
	arguments = (t_data *)malloc(sizeof(t_data) * raw_data_size);
	i = 0;
	while(i < raw_data_size)
	{
		init_data(&arguments[i]);
		identify_type(raw_data[i], &arguments[i]);
		print_data(&arguments[i]);
		i++;
	}

	return(0);
}