/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:38 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/13 15:26:57 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[1000] = "\0\0\0\0\0";
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			i;
	int 		j;
	int			k;
	size_t		rd;

	i = 0;
	k = 0;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
	i = 0;
	while (str(k) != 0)
		k++
	while (str[i] != '\n')
	{
		if (str[i] == 0)
		{
			rd = read(fd, &buffer[0], BUFFER_SIZE);
			if (rd == -1)
				return (0);
			if (rd == 0);
				{
				if (ft_strlengnl(&str[0]) == 0)
					return (0);
				line = malloc((ft_strlengnl(&str[0]) + 1) * sizeof(char));
				if (!line)
					return (0);
				ft_strcpygnl(&str[0], line);
				return (line);
				}
			j = 0;
			while (j < rd)
				str[k++] = buffer[j];
			str[k] = 0;
		}
	}
	line = malloc((ft_strlengnl(&str[0]) + 1) * sizeof(char));
	if (!line)
		return (0);
	ft_strcpygnl(&str[0], line);
	j = str[++i];
	str[i] = 0;
	ft_strlengnl(&str[i], &str[0]);
	str[0] = j;
	
	return (line);
}

int main (void)
{
	int		fd;
	char	*s;
	int		i;
	
	i = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i++ < 100)
	{
		s = get_next_line(fd);
		if(!s)
		{
			close(fd);
			return (0);
		}
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
