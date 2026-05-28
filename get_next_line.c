#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"
char    *get_next_line(int fd)
{
	static char    buffer[BUFFER_SIZE + 1];
	char        *line;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buffer[0])
	{
		line = my_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (ft_findnl(line))
			return(ft_shift_buffer(buffer), line);
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = my_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (ft_findnl(line))
			return (ft_shift_buffer(buffer), line);
	}
	buffer[0] = '\0';
	if (bytes_read < 0 || line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
/*
int    main(void)
{    
    int    fd = open("read_error.txt", O_RDONLY);
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
