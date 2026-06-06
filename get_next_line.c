/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:51:58 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/06/06 16:53:58 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

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
    printf("%s", line);
    free(line);
    return (0);
}
*/
