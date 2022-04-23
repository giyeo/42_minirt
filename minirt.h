/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:44:33 by rpaulino          #+#    #+#             */
/*   Updated: 2022/04/22 13:48:50 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

# include <string.h> //illegal

//_____________________________
typedef struct s_data
{
	char				*type;
	double				*coordinates;
	double				*norm_vector;
	double				brightness_lighting_ratio;
	double				diameter;
	double				height;
	int					*color;
	int					FOV;
}						t_data;

void	print_data(t_data *data);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_isdigit(int argument);
size_t	ft_strlen(const char *pointer);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

int		jump_to_another_sentence(char *string);
int		is_equal(char *str1, char *str2);
int		until_another_number(char *string);
int		until_another_space(char *string);
int		string_number_size(char *string);

char	*parse_a_str_from_two_intervals(char *string, int start, int end);
void	*parse_three_numbers(char *string, int is_double);
void	*parse_one_number(char *string, int is_double);
int		ms_parse_three_numbers(char *string, int is_double, int **ret_int, double **ret_double);
int		ms_parse_one_number(char *string, int is_double, int *ret_int, double *ret_double);

int		identify_type(char *string, t_data *data);
#endif