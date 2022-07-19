#include "../start_main/minirt.h"
/*
Open file safely and Read Everything (EASY).
Translate the file to data structures (MEDIUM).
Interpret the data structures into visuals (HARD).
*/

void	error(void)
{
	printf("%s \n", strerror(errno));
    exit(1);
}

int get_fd(char *argv[])
{
    int fd;

    fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		error();
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

char *get_argument(char *buffer, char **arguments, int *place)
{
	char	*new_buff;
	int		sub_string_length;
	
	sub_string_length = next_nl(buffer);
	if(buffer[0] == '\0')
		return NULL;
	if(sub_string_length == 0)
		new_buff = ft_substr(buffer, 1, strlen(buffer));
	else
	{
		arguments[*place] = ft_substr(buffer, 0, sub_string_length);
		(*place)++;
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

	while(buffer)
		buffer = get_argument(buffer, arguments, &i);
	arguments[i] = NULL;

	return arguments;
}

char	*read_data(int fd)
{
	char    *buffer;
	char    *temp;
	char	*temporary;
    ssize_t n;

	temp = (char *)malloc(sizeof(char) + 1);
    buffer = strdup("");
    n = read(fd, temp, 1);
	temp[1] = '\0';
	while (n > 0)
    {
		temporary = ft_strjoin(buffer, temp);
        free(buffer);
		buffer = temporary;
        n = read(fd, temp, 1);
    }
	close(fd);
    return (buffer);
}

char	*get_data_from_file(char *argv[])
{
	int     fd;

	fd = get_fd(argv);
	return (read_data(fd));
}

/*	Each Function free the allocated data it received.
	There are three steps in this program, read instructions file,
	parse it into a data structure, and use it to execute the program.
*/

int main(int argc, char *argv[])
{
	char    *buffer;
	char	**arguments;
	t_data	*cards;

	buffer = get_data_from_file(argv);
	arguments = get_arguments(buffer);
	

	//cards = get_cards(arguments);			TODO
	//ray_trace(cards);						TODO
	return (0);
}