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

int main(void)
{
	char *A = "A 0.2 255,255,255";
	char *C ="C -50,0,20 0,0,0 70";
	char *L ="L -40,0,30 0.7 255,255,255";
	char *pl ="pl 0,0,0 0,1.0,0 255,0,225";
	char *sp ="sp 0,0,20 20 255,0,0";
	char *cy ="cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255";


	// int *list = (int *)parse_three_numbers("134,145,155", 0);
	// double *dob = (double *)parse_three_numbers("1.1,13.4,14", 1);
	// int *integer = (int *)parse_one_number("3", 0);
	// double *doub = (double *)parse_one_number("34.2", 1);

	t_data ambient;
	t_data camera;
	t_data light;
	t_data plane;
	t_data sphere;
	t_data cylinder;
	init_data(&camera);
	init_data(&light);
	init_data(&ambient);
	init_data(&plane);
	init_data(&sphere);
	init_data(&cylinder);

	// printf("%d %d %d\n", list[0], list[1], list[2]);
	// printf("%f %f %f\n", dob[0], dob[1], dob[2]);
	// printf("%d\n", integer[0]);
	// printf("%f\n", doub[0]);
	identify_type(A, &ambient);
	print_data(&ambient);
	identify_type(C, &camera);
	print_data(&camera);
	identify_type(L, &light);
	print_data(&light);
	identify_type(pl, &plane);
	print_data(&plane);
	identify_type(sp, &sphere);
	print_data(&sphere);
	identify_type(cy, &cylinder);
	print_data(&cylinder);
	//printf("%ld\n", data.ambient->color.x);

	// free(integer);
	// free(doub);
	// free(list);
	// free(dob);
	return(0);
}