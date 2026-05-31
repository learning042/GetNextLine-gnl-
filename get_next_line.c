#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"
char    *get_next_line(int fd)
{
	static char    buffer[BUFFER_SIZE + 1];
	char        *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = ft_get_line(fd, buffer, &line);
	return (line);
}
/*
int    main(void)
{    
    int    fd = open("shrek.txt", O_RDONLY);
    char    *line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
	free(line);
        line = get_next_line(fd);
    }
    return (0);
}
*/
