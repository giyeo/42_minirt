#include "minirt.h"

void	parsing_error(int i, int j)//t_data *data)
{
	printf("Parsing error at line: %d column: %d", i + 1, j + 1);
	//free_data(data);
	exit(1);
}

void	print_data(t_data *data)
{
	printf("type: %s\n", data->type);
	if(data->coordinates)
		printf("Coordinates: %f,%f,%f\n",
		data->coordinates[0],
		data->coordinates[1],
		data->coordinates[2]);
	if(data->norm_vector)
		printf("Norm_vector: %f,%f,%f\n",
		data->norm_vector[0],
		data->norm_vector[1],
		data->norm_vector[2]);
	if(data->diameter)
		printf("diameter: %f\n",
		data->diameter);
	if(data->height)
		printf("height: %f\n",
		data->height);
	if(data->FOV)
		printf("FOV: %d\n", data->FOV);
	if(data->brightness_lighting_ratio)
		printf("brightness_lighting_ratio: %f\n",
		data->brightness_lighting_ratio);
	if(data->color)
		printf("Color: %d,%d,%d\n",
		data->color[0],
		data->color[1],
		data->color[2]);
	printf("-------------------------------\n");
}
