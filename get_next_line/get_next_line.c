/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:38 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/09 18:22:31 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* char	*get_next_line(int fd)
{
	char	*s;
	
	return (s);	
}
 */
int	ft_size_file(char *filename)
{
	int		fd;
	int		nb_read;
	int		count;
	char	*buf[1];

	fd = 0;
	nb_read = 1;
	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, 1);
		if (nb_read == -1)
			return (-1);
		count++;
	}
	close(fd);
	return (count);
}

int	ft_read_file(char *filename, char *dico, int len)
{
	int		fd;
	int		nb_read;
	//char	buf[1025];

	fd = 0;
	nb_read = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	nb_read = read(fd, dico, len);
	if (nb_read == -1)
		{
			close(fd);
			return(-1);
		}
	dico[1024] = '\0';
	close(fd);
	return (0);
}
int ft_write_file(char *filename, char *dico)
{
	int		fd;
	size_t	i;
	char	c;

	fd = 0;
	i = 0;
	c = '\n';
	fd = open(filename, O_CREAT|O_WRONLY, 777);
	if (fd == -1)
		return (-1);
	while(dico[i] != '\n') // passe la premiere ligne
		i++;
	while (dico[i]!= 0)
	{
		while(dico[i] != ',' && dico[i] != 0) //la premiere virgule apres \n indique la fin du mot.
			write(fd, &dico[i++], 1);
		while(dico[i] != '\n' && dico[i] != 0)
			i++;
		write(fd, &c, 1);
		i++;
	}
	c = '\0';
	write(fd, &c, 1);
	close(fd);
	return (0);
}


int main (void)
{
	char	*filename;
	char	*dico;
	int	size;
	int		fd;
	
	filename = "dicoanglais.txt";
	size = ft_size_file (filename);
	if (size == -1)
		return (0);
	dico = (char *)malloc((size + 1) * sizeof(char));
	if (dico == NULL)
		return (0);
	fd = ft_read_file(filename, dico, 1024);
	if (fd == -1)
	{	
		free(dico);
		return (0);
	}
	filename = "test.txt";
	fd = ft_write_file(filename, dico);
	/* while (dico[fd] != 0)
	{
		printf("%c(%i)", dico[fd], dico[fd]);
		fd++;
	} */
	free(dico);
	return (0);
}
