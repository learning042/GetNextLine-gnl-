/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:00:46 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/06/09 10:41:08 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX + 1][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || FD_MAX < 0 || fd > FD_MAX)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = ft_get_line(fd, buffer[fd], &line);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int    main(void)
{    
    int	fd = open("hello.txt", O_RDONLY);
    int	fd2 = open("world.txt", O_RDONLY);	
    char    *line = get_next_line(fd);
    printf("%s", line);
	char    *line2 = get_next_line(fd2);
	printf("%s", line2);
	line = get_next_line(fd);
	printf("%s", line);
    return (0);
}
*/
