/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:48:28 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/05/05 19:15:27 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 3
#include <unistd.h>

size_t	my_strlen(char *str, char term)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != term) 
		++len;
	return (len);
}

char	*my_strcat(char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;

	while (s1[i])
		++i;
	while (s2[j] && s2[j] != '\n')
	{
		s1[i] = s2[j];
		++i;
		++j;
	}
	if (s2[j] == '\n')
	{
		s1[i] = '\n';
		s1[i + 1] = '\0';
		return (s1);
	}
	s1[i] = '\0';
	return (s1);
}

char	*my_strjoin(char *s1, char *s2, int was_allocated)
{
	static char	*s_conc;
	size_t	i;
	size_t	j;
	
	s_conc = malloc(my_strlen(s1, '\0') + my_strlen(s2, '\n') + 1);
	if (s_conc == NULL)
		return (NULL);
	i = 0;
	j = 0;
 
	s_conc[i] = '\0';
	my_strcat(s_conc, s1);
	my_strcat(s_conc, s2);
	if (was_allocated)
		free(s1);
	s1 = s_conc;
	return (s_conc);
}

void	shift_to_beggining(char arr[], int nindex, int size)
{
	size_t	i;
	char	tmp;

	i = nindex + 1; 
	while (i < size)
	{	
		tmp = arr[i];
		arr[i] = arr[i - nindex - 1];
		arr[i - nindex - 1] = tmp;
		++i;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	size_t		i;

	read(fd, buffer, BUFFER_SIZE);
	line = malloc(BUFFER_SIZE + 1);
	my_strjoin(line, buffer, 1);
	while (line[my_strlen(line, '\n') - 1] != '\n')
	{
		if (read(fd, buffer, BUFFER_SIZE) < BUFFER_SIZE)
		{
			my_strjoin(line, buffer, 1);
			break;
		}
		my_strjoin(line, buffer, 1);	
	}
	return (line);
}

int	main(void)
{
	int		fd = open("world.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
