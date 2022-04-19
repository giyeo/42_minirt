/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:44:36 by rpaulino          #+#    #+#             */
/*   Updated: 2022/04/18 23:44:36 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
Open file safely and Read Everything (EASY).
Translate the file to data structures (MEDIUM).
Interpret the data structures into visuals (HARD).
*/

int main(int argc, char *argv[])
{
	t_data data;

	printf("%ld\n", sizeof(data));
	exit(1);
	//t_entity *data;
	//data = get_input_check_errors_and_put_on_data_structures(argc, argv);
	//render_the_data_structures_in_the_scene(data);
	int fd;
	ssize_t n;
	char *buffer;
	char *temp[10];

	buffer = (char *)malloc(sizeof(char) * 10);
	// assume foobar.txt is already created 
	n = 1;
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		printf("%s \n", strerror(errno));
	else
		printf("Success! fd:%d file:%s\n", fd, argv[1]);
	while (n > 0)
	{
		write(1, temp, n);
		n = read(fd, temp, 10);
	}
	close(fd);
	free(buffer);
	return 0; 
}