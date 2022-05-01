#include "minirt.h"
/*
Open file safely and Read Everything (EASY).
Translate the file to data structures (MEDIUM).
Interpret the data structures into visuals (HARD).
*/
int get_fd(char *argv[])
{
    int fd;

    fd = open(argv[1], O_RDONLY);
	if(fd == -1)
    {
		printf("%s \n", strerror(errno));
        exit(1);
    }
	else
		printf("Success! fd:%d file:%s\n\n", fd, argv[1]);
    return (fd);
}

int	count_arguments(char *buffer)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while(buffer[i] != '\0')
	{
		if(buffer[i] == '\n' && buffer[i + 1] != '\n')
			n++;
		i++;
	}
	return(n);
}

int	next_nl(char *buffer)
{
	int i;

	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return i;
}
char *get_argument(char *buffer, char **arguments, int place)
{
	char *new_buff;

	int sub_string_length = next_nl(buffer);

	if(!sub_string_length)
		new_buff = ft_substr(buffer,1,strlen(buffer));
	else
	{
		arguments[place] = ft_substr(buffer, 0, sub_string_length);
		new_buff = ft_substr(buffer,sub_string_length,strlen(buffer));
	}
	free(buffer);
	return new_buff;
}


char **get_arguments(char *buffer){
	int		number_of_arguments;
	int		i;
	char	**arguments;

	i = 0;
	number_of_arguments = count_arguments(buffer);

	arguments = (char **)malloc(sizeof(char *) * number_of_arguments + 1);
	exit(0);



	while(buffer)
		buffer = get_argument(buffer, arguments, i++);
	arguments[i] = NULL;
	return arguments;
}

char *get_buffer(int fd)
{
	char    *buffer;
	char    temp[1];
    ssize_t n;

    buffer = strdup("");
    n = read(fd, temp, 1);
	while (n > 0)
    {
        buffer = strncat(buffer, temp, 1);
        n = read(fd, temp, 1);
    }
    return (buffer);
}

int main(int argc, char *argv[])
{
	int     fd;
	char    *buffer;
	char	**arguments;
	t_data	*cards;

	fd = get_fd(argv);
    buffer = get_buffer(fd);
	close(fd);
	arguments = get_arguments(buffer);
	free(buffer);
	//cards = get_cards(arguments);			TODO
	//free(arguments);						TODO
	//ray_trace(cards);						TODO
	//free_cards(cards);					TODO
	return (0);
}