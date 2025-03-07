/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:00:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/07 18:20:44 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	int		i;
	
	i = 0;
	set_signals();
	while (i == 0)
	{
		input = readline("minishell> ");
		if (!input)
			i = 1;
		else
		{
			if (*input)
				add_history(input);
			i = ft_strnstr(&input[0], "exit", ft_strlen(&input[0]) != 0);	
			free(input);
		}	
	}
	if(input)
		free(input);
	unset_signals();
	return (0);
}