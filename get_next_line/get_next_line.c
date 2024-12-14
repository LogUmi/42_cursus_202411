/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:38 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/14 19:30:35 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[30000] = "\0\0\0\0\0";
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			i;
	int			j;
	int			k;
	int			rd;

	i = 0;
	k = 0;
	rd = -2;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
	i = 0;
	while (str[k] != 0)
		k++;
	while (str[i] != '\n' && rd != 0)
	{
		if (str[i] == 0)
		{
			rd = read(fd, &buffer[0], BUFFER_SIZE);
			if (rd < 0)
			{
				j = 0;
				while (j < 30000)
					str[j++] = 0;
				return (0);
			}
			if (rd != 0)
			{	
				j = 0;
				while (j < rd)
					str[i++] = buffer[j++];
				str[i] = 0;
				i = k - 1;
				k += j;
			}
		}
		if(rd != 0)
			i++;
	}
	if (rd == 0 && i == 0 && str[i] == 0)
		return (0);
	if (str[i] == 0)
		i--;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	return (ft_strncpygnl(&str[0], line, i + 1));
}
/* 
int main (void)
{
	int		fd;
	char	*s;
	int		i;
	
	i = 0;
	fd = open("read_error.txt", O_RDONLY);
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
 */