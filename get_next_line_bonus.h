/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-v <tpinto-v@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:59:06 by tpinto-v          #+#    #+#             */
/*   Updated: 2026/05/27 22:06:01 by tpinto-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

int		my_strlen(char *str, char term);
char	*my_strjoin(char *s1, char *s2);
void	ft_shift_buffer(char *buf);
char	*ft_get_line(int fd, char *buf, char **s);
char	*get_next_line(int fd);
int		ft_findnl(char *s);

#endif
