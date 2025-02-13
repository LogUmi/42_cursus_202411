/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:58:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/12 21:59:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	test_pid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] > 47 & str[i] < 58)
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (i);
}
