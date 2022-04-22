#include "minirt.h"

size_t	ft_strlen(const char *pointer)
{
	size_t counter;

	counter = 0;
	while (pointer[counter] != '\0')
		counter++;
	return (counter);
}

int		ft_isdigit(int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	if (argument == '-')
		return (1);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointerdest;
	unsigned char	*pointersource;

	pointerdest = dest;
	pointersource = (unsigned char*)src;
	if (pointerdest == 0 && pointersource == 0)
		return (dest);
	while (n-- > 0)
		*pointerdest++ = *pointersource++;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * len);
	if (dup)
		ft_memcpy(dup, s, len);
	return (dup);
}

char *parse_a_str_from_two_intervals(char *string, int start, int end)
{
	int i = 0;
	char *temp;

	temp = (char *)malloc(sizeof(char) * (end - start) + 1);
	while(start + i < end)
	{
		temp[i] = string[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	string_number_size(char *string)
{
	int i = 0;
	while(ft_isdigit(string[i]) || string[i] == '.')
		i++;
	return (i);
}


void	*parse_three_numbers(char *string, int is_double)
{
	char	*temp;
	int		color;
	double	*list_double;
	int		*list;
	int		size;
	int		i;

	color = 0;
	i = 0;
	if(is_double)
		list_double = (double *)malloc(sizeof(double) * 3);
	else
		list = (int *)malloc(sizeof(int) * 3);
	while(string[i] != '\0' && color < 3)
	{
		if(ft_isdigit(string[i]))
		{
			size = string_number_size(string + i);
			temp = parse_a_str_from_two_intervals(string, i, i + size);
			if(is_double)
				list_double[color] = atof(temp);
			else
				list[color] = atoi(temp);
			free(temp);
			color++;
			i += size - 1;
		}
		i++;
	}
	if(is_double)
		return list_double;
	return (list);
}

void	*parse_one_number(char *string, int is_double)
{
	double *double_number;
	int *int_number;
	int i = 0;
	int size;
	char *temp;
	if(is_double)
		double_number = (double *)malloc(sizeof(double) * 1);
	else
		int_number = (int *)malloc(sizeof(int) * 1);
	while(string[i] != '\0')
	{
		if(ft_isdigit(string[i]))
		{
			size = string_number_size(string + i);
			temp = parse_a_str_from_two_intervals(string, i, i + size);
			if(is_double)
				double_number[0] = atof(temp);
			else
				int_number[0] = atoi(temp);
			free(temp);
			if(is_double)
				return (double_number);
			return (int_number);
		}
		i++;
	}
}

int	until_another_space(char *string)
{
	int i = 0;
	while(string[i] != ' ' && string[i] != '\0')
		i++;
	if(string[i] == '\0')
		return (-1);
	return (i);
}

int	until_another_number(char *string)
{
	int i = 0;
	while(!ft_isdigit(string[i]) && string[i] != '\0')
		i++;
	if(string[i] == '\0')
		return (-1);
	return (i);
}

int	check_for_ambient(char *string, t_data *data)
{
	double		*lightning_ratio;
	int			*color;
	
	int i = 0;

	i += until_another_number(&string[i]);

	data->brightness_lighting_ratio = *(double *)parse_one_number(&string[i], 1);

	i += until_another_space(&string[i]);
	i += until_another_number(&string[i]);

	data->color = (int *)parse_three_numbers(&string[i], 0);

	return (1);
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

// 3DOUBLE -> 3DOUBLE -> DOUBLE -> DOUBLE -> INT -> 3INT
int	is_equal(char *str1, char *str2)
{
	if(!strcmp(str1, str2))	
		return (1);
	return (0);
}

int	super_att(char *type, char *string, t_data *data)
{
	int i = 0;

	data->type = type;
	i += until_another_number(&string[i]);
	if(!is_equal(type,"A"))
	{
		data->coordinates = (double *)parse_three_numbers(&string[i], 1);
		i += until_another_space(&string[i]);
		i += until_another_number(&string[i]);
	}
	if(is_equal(type,"C") || is_equal(type,"pl") || is_equal(type,"cy"))
	{
		data->norm_vector = (double *)parse_three_numbers(&string[i], 1);
		i += until_another_space(&string[i]);
		i += until_another_number(&string[i]);
		if(is_equal(type,"C"))
		{
			data->FOV = *(int *)parse_one_number(&string[i], 0);
			return (1);
			printf("a\n");
		}
	}
	if(!is_equal(type,"pl") && !is_equal(type,"C"))
	{
		if(is_equal(type,"sp") || is_equal(type,"cy"))
			data->diameter = *(double *)parse_one_number(&string[i], 1);
		else
			data->brightness_lighting_ratio = *(double *)parse_one_number(&string[i], 1);
		i += until_another_space(&string[i]);
		i += until_another_number(&string[i]);
	}
	if(is_equal(type,"cy"))
	{
		data->height = *(double *)parse_one_number(&string[i], 1);
		i += until_another_space(&string[i]);
		i += until_another_number(&string[i]);
	}
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
			return(super_att("pl", string, data));
		else if(string[i] == 's')
			return(super_att("sp", string, data));
		else if(string[i] == 'c')
			return(super_att("cy", string, data));
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
	int i = 0;
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