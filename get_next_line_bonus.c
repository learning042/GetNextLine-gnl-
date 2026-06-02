#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"
char    *get_next_line(int fd)
{
	static char    buffer[1024][BUFFER_SIZE + 1];
	char        *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = ft_get_line(fd, buffer[fd], &line);
	return (line);
}
/*
int    main(void)
{    
    int	fd = open("hello.txt", O_RDONLY);
    int	fd2 = open("world.txt", O_RDONLY);	
    char    *line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
	free(line);
        line = get_next_line(fd);
    }
char    *line2 = get_next_line(fd2);
    while (line2 != NULL)
    {
        printf("%s", line2);
	free(line2);
        line2 = get_next_line(fd2);
    }
    return (0);
}
*/
