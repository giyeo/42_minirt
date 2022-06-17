#include "../start_main/minirt.h"

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

void	*parse_three_numbers(char *string, int is_double)
{
	int		size;
	char	*temp;
	int		color;
	double	*list_double;
	int		*list;
	int		i;

	color = 0;
	i = -1;
	if(is_double)
		list_double = (double *)malloc(sizeof(double) * 3);
	else
		list = (int *)malloc(sizeof(int) * 3);
	while(string[i++] != '\0' && color < 3)
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
	}
	if(is_double)
		return list_double;
	return (list);
}

void	*parse_one_number(char *string, int is_double)
{
	double	*double_number;
	int		*int_number;
	int		i; 
	char	*temp;
	
	i = -1;
	if(is_double)
		double_number = (double *)malloc(sizeof(double) * 1);
	else
		int_number = (int *)malloc(sizeof(int) * 1);
	while(string[i++] != '\0')
	{
		if(ft_isdigit(string[i]))
		{
			temp = parse_a_str_from_two_intervals(string, i, i + string_number_size(string + i));
			if(is_double)
				double_number[0] = atof(temp);
			else
				int_number[0] = atoi(temp);
			free(temp);
			if(is_double)
				return (double_number);
			return (int_number);
		}
	}
	return(0);
}

int		ms_parse_three_numbers(char *string, int is_double, int **ret_int, double **ret_double)
{
	if(is_double)
		*ret_double = (double *)parse_three_numbers(string, 1);
	else
		*ret_int = (int *)parse_three_numbers(string, 0);
	return (jump_to_another_sentence(string));
}

int		ms_parse_one_number(char *string, int is_double, int *ret_int, double *ret_double)
{
	if(is_double)
		*ret_double = *(double *)parse_one_number(string, 1);
	else
		*ret_int = *(int *)parse_one_number(string, 0);
	return (jump_to_another_sentence(string));
}
