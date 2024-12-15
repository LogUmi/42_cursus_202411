/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:38 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/15 19:41:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"


char	*ft_strncpygnl(char *src, char *dst, int n, int way)
{
	int	i;

	i = 0;
	if (!src || !dst)
		return (0);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (way == 1)
	{
		i = 0;
		while (src[i + n] != 0)
		{
			src[i] = src[i + n];
			i++;
		}
		while (src[i] != 0)
		src[i++] = 0;
	}
	return (dst);
}

static char	*ft_getinit(char *buffer, char *str, int *k, int way)
{
	char	*line;

	line = 0;
	if (way == 0)
		while (way < STATIC_SIZE)
			str[way++] = 0;
	if (way == 1)
	{
		while ((*k) < BUFFER_SIZE)
			buffer[(*k)++] = 0;
		(*k) = 0;
		while (str[(*k)] != 0)
			(*k)++;
	}
	if (way == 2)
	{
		line = malloc(((*k) + 2 )* sizeof(char));
		if (!line)
			return (0);
		line = ft_strncpygnl(&str[0], line, (*k) + 1, 1);
	}
	return (line);
}

int	ft_readfile(int fd,char *buffer,char *str, int i[])
{
	int	rd;
	
	rd = 0;
	if (str[i[0]] == 0)
		{
			rd = read(fd, &buffer[0], BUFFER_SIZE);
			if (rd < 0)
			{
				ft_getinit(&str[0], &str[0], &i[0], 0);
				return (-1);
			}
			if (rd != 0)
			{	
				ft_strncpygnl(&buffer[0], &str[i[0]], rd, 0);		
				i[0] = i[1] - 1;
				i[1] += rd;
			}
		}
		if(rd != 0)
			i[0]++;
		return (rd);
}
char	*get_next_line(int fd)
{
	static char	str[STATIC_SIZE] = "\0\0\0\0\0";
	char		buffer[BUFFER_SIZE];
	int			i[2];
	int			rd;

	i[0] = 0;
	i[1] = 0;
	rd = -2;
	if (fd < 0 || BUFFER_SIZE == 0 || STATIC_SIZE == 0)
		return (0);
	ft_getinit(&buffer[0], &str[0], &i[1], 1);
	while (str[i[0]] != '\n' && rd != 0)
	{
		rd = ft_readfile(fd, &buffer[0], &str[0], i);
	}
	if (rd == 0 && i[0] == 0 && str[i[0]] == 0)
		return (0);
	if (str[i[0]] == 0)
		i[0]--;
	return (ft_getinit(&str[0], &str[0], &i[0], 2));
}

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
