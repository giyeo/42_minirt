#include "minirt.h"

int		ft_isdigit(int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	return (0);
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

int main(void)
{
	int *list = (int *)parse_three_numbers("134,145,155", 0);
	double *dob = (double *)parse_three_numbers("1.1,13.4,14", 1);
	printf("%d %d %d\n", list[0], list[1], list[2]);
	printf("%f %f %f\n", dob[0], dob[1], dob[2]);
	int *integer = (int *)parse_one_number("3", 0);
	double *doub = (double *)parse_one_number("34.2", 1);
	printf("%d\n", integer[0]);
	printf("%f\n", doub[0]);

	free(integer);
	free(doub);
	free(list);
	free(dob);
	return(0);
}