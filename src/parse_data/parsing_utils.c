#include "../start_main/minirt.h"

int	string_number_size(char *string)
{
	int i = 0;
	while(ft_isdigit(string[i]) || string[i] == '.')
		i++;
	return (i);
}

int	until_another_space(char *string)
{
	int i = 0;
	while(string[i] != ' ' && string[i] != '\0')
		i++;
	if(string[i] == '\0')
		return (0);
	return (i);
}

int	until_another_number(char *string)
{
	int i = 0;

	while(!ft_isdigit(string[i]) && string[i] != '\0')
		i++;
	if(string[i] == '\0')
		return (0);
	return (i);
}

// 3DOUBLE -> 3DOUBLE -> DOUBLE -> DOUBLE -> INT -> 3INT
int	is_equal(char *str1, char *str2)
{
	if(!strcmp(str1, str2))	
		return (1);
	return (0);
}

int jump_to_another_sentence(char *string)
{
	int i = 0;
	i += until_another_space(&string[i]);
	i += until_another_number(&string[i]);
	return (i);
}