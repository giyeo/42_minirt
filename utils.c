#include "minirt.h"

void	parsing_error(int i, int j, t_data *data)
{
	printf("Parsing error at line: %d column: %d", i + 1, j + 1);
	//free_data(data);
	exit(1);
}