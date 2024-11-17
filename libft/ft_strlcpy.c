/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:40:41 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/08 18:47:04 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((i < (size - 1)) && (src[i] != 0))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	while (!(src[i] == 0))
		i++;
	return (i);
}
/* #include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>

int	main(void)
{
	char array [] = "0123456789";
	char arraybis [] = "9876543210";
	char arrayter [] = "0123456789";
	char arrayqua[] = "9876543210";
	int i = 0;
	
	printf("array 1 : %s \narray 2 : %s\n",array, arraybis);
	printf("Pas tienne : %zu ... ", strlcpy(arraybis, array, 8));
	printf("array 1 : %s \n", arraybis);
	while (i < 10)
		printf("%d ",arraybis[i++]);					
	printf ("\n");	
	printf("Tienne : %zu ...", ft_strlcpy(arrayqua, arrayter, 8));
	printf("array 2 : %s\n",arrayqua);
	i = 0;
	while (i < 10)
		printf("%d ",arrayqua[i++]);					
	printf ("\n");
	return (0);
} */