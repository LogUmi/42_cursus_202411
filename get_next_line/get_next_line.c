/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:38 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/11 19:23:43 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

 char	*get_next_line(int fd)
{
	char	*s;
	char	buffer[BUFFER_SIZE];
	if (fd < 0)
		return (0);
	
	buffer[0] = 'd';
	s = &buffer[0];
	return (s);	
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
		//free(s);
	}
	close(fd);
	return (0);
}
