#include "minirt.h"

int	super_att(char *type, char *string, t_data *data)
{
	int i;

	i = 0;
	i = until_another_number(&string[i]);
	data->type = type;
	if(!is_equal(type, "A"))
		i += ms_parse_three_numbers(&string[i], 1, NULL, &data->coordinates);
	if(is_equal(type, "C") || is_equal(type, "pl") || is_equal(type, "cy"))
		i += ms_parse_three_numbers(&string[i], 1, NULL, &data->norm_vector);
	if(is_equal(type, "sp") || is_equal(type, "cy"))
		i += ms_parse_one_number(&string[i], 1, NULL, &data->diameter);
	if(is_equal(type, "A") || is_equal(type, "L"))
		i += ms_parse_one_number(&string[i], 1, NULL, &data->brightness_lighting_ratio);
	if(is_equal(type, "cy"))
		i += ms_parse_one_number(&string[i], 1, NULL, &data->height);
	if(is_equal(type, "C"))
		data->FOV = *(int *)parse_one_number(&string[i], 0);
	if(!is_equal(type, "C"))
		data->color = (int *)parse_three_numbers(&string[i], 0);
	return (1);
}

int	identify_type(char *string, t_data *data)
{
	int i = 0;
	while(string[i])
	{
		if(string[i] == 'A')
			return(super_att("A", &string[i + 1], data));
		else if(string[i] == 'C')
			return(super_att("C", &string[i + 1], data));
		else if(string[i] == 'L')
			return(super_att("L", &string[i + 1], data));
		else if(string[i] == 'p')
			return(super_att("pl", &string[i + 1], data));
		else if(string[i] == 's')
			return(super_att("sp", &string[i + 1], data));
		else if(string[i] == 'c')
			return(super_att("cy", &string[i + 1], data));
		else
			i++;
	}
	return(0);
}

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
