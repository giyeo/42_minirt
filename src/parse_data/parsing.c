#include "../start_main/minirt.h"

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

