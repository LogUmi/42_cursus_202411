/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_repeated_words.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:38 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/11 16:51:29 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while (i < n && s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	if (n == i)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
	dico[len] = '\0';
	close(fd);
	return (0);
}
int ft_write_file(char *filename, char *dico, int len)
{
	int		fd;
	int		i;
	int		j;
	int		k;
	int		x[3] = {0, 0, 0};
	char	c;
	char	test[2][500];

	fd = 1;
	i = 0;
	k = 0;
	c = '\n';
	fd = open(filename, O_CREAT|O_WRONLY, 777);
	if(filename == 0)
		return(-1);
	if (fd == -1)
		return (-1);
	while(i < 100)
	{
		test[0][i] = 0;
		test[1][i++] = 0;
	}
	i = 0;
	while (i < (len))
	{
		j = 0;
		k = i;
		while(dico[i] != '\n' && i < len)
		{
			test[0][j++] = dico[i++];
			x[0]++;
		}
		test[0][j] = c;
		j = 0;
		i++;
		while(dico[i] != '\n' && i < len)
		{
			test[1][j++] = dico[i++];
			x[1]++;
		}
		if (x[1] == x[0])
		{
			if (ft_strncmp(&test[0][0], &test[1][0], x[0]) != 0)
				write(fd, &test[0][0], x[0] + 1);
		}
		else
			write(fd, &test[0][0], x[0] + 1);
		i = k + x[0] + 1;
		x[0] = 0;
		x[1] = 0;
	}
	close(fd);
	return (0);
}


int main (void)
{
	char	*filename;
	char	*dico;
	int		size;
	int		fd;
	
	filename = "dico0.txt";
	size = ft_size_file (filename);
	if (size == -1)
		return (0);
	dico = (char *)malloc((size + 1) * sizeof(char));
	if (dico == NULL)
		return (0);
	fd = ft_read_file(filename, dico, size);
	if (fd == -1)
	{	
		free(dico);
		return (0);
	}
	filename = "dico1.txt";
	fd = ft_write_file(filename, dico, size);
	/* while (dico[fd] != 0)
	{
		printf("%c(%i)", dico[fd], dico[fd]);
		fd++;
	} */
	free(dico);
	return (0);
}