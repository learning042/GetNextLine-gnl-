/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:48:28 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/04/29 19:19:30 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 3
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*my_strjoin(char *s1, char *s2, int *s1_allocated)
{
	static char	*s_conc;
	size_t	i;
	size_t	j;
	
	s_conc = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s_conc == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s_conc[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		s_conc[i] = s2[j];
		++j;
		++i;
	}
	s_conc[i] = '\0';
	if (*s1_allocated)
		free(s1);
	return (s_conc);

}

char	*get_next_line(int fd)
{

}

int	main(void)
{
	int		fd = open("world.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
