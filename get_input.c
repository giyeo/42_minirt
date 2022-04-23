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
	//arguments = get_arguments(buffer);	TODO
	free(buffer);
	//cards = get_cards(arguments);			TODO
	//free(arguments);						TODO
	//ray_trace(cards);						TODO
	//free_cards(cards);					TODO
	return (0);
}