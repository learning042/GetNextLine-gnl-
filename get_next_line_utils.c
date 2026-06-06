/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:59:23 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/06/06 16:07:33 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	my_strlen(char *s, char term)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != term)
		++len;
	return (len);
}

static int	ft_findnl(char *s)
{
	int	len;
	int	nl_index;

	len = my_strlen(s, '\0');
	nl_index = my_strlen(s, '\n');
	if (len == nl_index)
		return (0);
	return (1);
}

static char	*my_strjoin(char *s1, char *s2)
{
	char	*s_conc;
	int		i;
	int		j;

	s_conc = malloc(my_strlen(s1, '\0') + my_strlen(s2, '\n') + 2);
	if (s_conc == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		s_conc[i] = s1[i];
	while (s2[j] && s2[j] != '\n')
	{
		s_conc[i + j] = s2[j];
		++j;
	}
	if (s2[j] == '\n')
	{
		s_conc[i + j] = '\n';
		s_conc[i + j + 1] = '\0';
	}
	else
		s_conc[i + j] = '\0';
	free(s1);
	return (s_conc);
}

static void	ft_shift_buffer(char *buf)
{
	int	i;
	int	nl_index;

	nl_index = my_strlen(buf, '\n') + ft_findnl(buf);
	i = 0;
	while (buf[nl_index + i])
	{
		buf[i] = buf[nl_index + i];
		++i;
	}
	buf[i] = '\0';
}

char	*ft_get_line(int fd, char *buf, char **s)
{
	int	bytes_read;

	if (buf[0])
	{
		*s = my_strjoin(*s, buf);
		if (!(*s))
			return (NULL);
		if (ft_findnl(*s))
			return (ft_shift_buffer(buf), *s);
	}
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		*s = my_strjoin(*s, buf);
		if (!(*s))
			return (NULL);
		if (ft_findnl(*s))
			return (ft_shift_buffer(buf), *s);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	buf[0] = '\0';
	if (bytes_read < 0 || (*s)[0] == '\0')
		return (free(*s), NULL);
	return (*s);
}
