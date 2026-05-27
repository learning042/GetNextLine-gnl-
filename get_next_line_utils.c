/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:59:23 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/05/27 22:30:11 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		my_strlen(char *s, char term)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != term)
		++len;
	return (len);
}

int		ft_findnl(char *s)
{
	int	len;
	int	nl_index;

	len = my_strlen(s, '\0');
	nl_index = my_strlen(s, '\n');
	if (len == nl_index)
		return (0);
	return (1);
}

char	*my_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		++i;
	while (s2[j] && s2[j] != '\n')
	{
		s1[i + j] =  s2[j];
		++j;
	}
	if (s2[j] == '\n')
	{
		s1[i + j] = '\n';
		s1[i + j + 1] = '\0';
	}
	else
		s1[i + j] = '\0';
	return (s1);
}

char	*my_strjoin(char *s1, char *s2)
{
	int 	len1;
	int		len2;
	char	*s_conc;	

	if (!s1 || !s2)
		return (NULL);
	len1 = my_strlen(s1, '\0');
	len2 = my_strlen(s2, '\n');
	s_conc = malloc(len1 + len2 + 2);
	if (s_conc == NULL)
		return (NULL);
	s_conc[0] = '\0';
	my_strcat(s_conc, s1);
	my_strcat(s_conc, s2);
	free(s1);
	return (s_conc);
}

void	ft_shift_buffer(char *buf)
{
	int	i;
	int	nl_index;

	nl_index = my_strlen(buf, '\n');
	i = 0;
	while (buf[nl_index + i + 1])
	{
		buf[i] = buf[nl_index + i + 1];
		buf[nl_index + i + 1] = '\0';
		++i;
	}
	buf[i] = '\0';
}
