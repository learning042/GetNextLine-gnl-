/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:40:45 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/05/26 16:08:30 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1

int	my_strlen(char *s, char term)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != term)
		++len;
	return (len);
}

char 	*ft_strjoin(char *s1, char *s2)
{
	char	*s_conc;
	int	i;
	int	j;
	int	memalloc;

	memalloc = my_strlen(s1, '\0') + my_strlen(s2, '\n') + 1;
	s_conc = malloc(memalloc);
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s_conc[i] = s1[i];
		++i;
	}
	while (s2[j] && s2[j - 1] != '\n')
	{
		s_conc[i + j] = s2[j];
		++j;
	}
	s_conc[i + j] = '\0';
	free(s1);
	s1 = s_conc;
	return (s_conc);
}

int	find_nl(char *s)
{
	int	index;

	index = 0;
	while (s[index] && s[index] != '\n')
		++index;
	if (s[index] == '\0')
		return (-1);
	return (index);
}


char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line || find_nl(line) != -1)
			break;
	}
	return (line);
}

	

int	main(void)
{
	int	fd = open("world.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s", line);
	free(line);

	return (0);
}
