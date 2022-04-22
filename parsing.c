/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:00:28 by rpaulino          #+#    #+#             */
/*   Updated: 2022/04/22 00:15:20 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Your program must take as a first argument a scene description file with the .rt
// extension.
// ◦ Each type of element can be separated by one or more line break(s).
// ◦ Each type of information from an element can be separated by one or more
// space(s).
// ◦ Each type of element can be set in any order in the file.
// ◦ Elements which are defined by a capital letter can only be declared once in
// the scene.


int	check_for_ambient(char *string, t_data *data)
{
	t_ambient	*ambient;
	double		*lightning_ratio;
	int			*color;
	
	int i = 0;
	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	i += until_another_space(&string[i]);
	color = (int *)parse_three_numbers(&string[i], 0);
	i += until_another_space(&string[i]);
	lightning_ratio = (double *)parse_one_number(&string[i], 1);

	data->ambient->color = color;
	data->ambient->lighting_ratio = *lightning_ratio;

	return (1);
}

int	identify_type(char *string, t_data *data)
{
	int i = 0;
	while(string[i])
	{
		if(string[i] == 'A')
			return(check_for_ambient(&string[i + 1], data));
		// else if(string[i] == 'C')
		// 	return(check_for(string[i], string, data));
		// else if(string[i] == 'L')
		// 	return(check_for(string[i], string, data));
		// else if(string[i] == 'p')
		// 	return(check_for(string[i], string, data));
		// else if(string[i] == 's')
		// 	return(check_for(string[i], string, data));
		// else if(string[i] == 'c')
		// 	return(check_for(string[i], string, data));
		else
			i++;
	}
	return(0);
}
int main(void)
{
	char *A = "A 0.2 255,255,255";
	char *C ="C -50,0,20 0,0,0 70";
	char *L ="L -40,0,30 0.7 255,255,255";
	char *pl ="pl 0,0,0 0,1.0,0 255,0,225";
	char *sp ="sp 0,0,20 20 255,0,0";
	char *cy ="cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255";
	
	t_data data;
	int i = 0;
	
	identify_type(A, &data);
	printf("%ld", data.ambient->color.x);

	printf("\n");
	return(0);
}
