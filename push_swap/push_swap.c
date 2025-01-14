/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:20 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/14 19:01:03 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include push_swap.h

int	ft_error(void)
{
	
	ft_printf("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	char	**s
	
	s = NULL;
	if (argc < 3)
	{
		if (argc == 1)
			return (ft_error);
		if(ft_strlen(argv[1]) < 3)
			return (ft_error);
		s = ft_split(argv[1], 32)
		if (!s)
			return(ft_error)
	
	}
	else
	{
		while (argc != 0)
			if 
	}
	
}