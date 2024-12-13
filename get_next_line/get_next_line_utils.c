/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:30 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/13 14:33:59 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlengnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strcpygnl(const char *src, char *dst)
{
	int	i;

	i = 0;
	if (!src || !dst)
		return (0);
	while (i < ft_strlengnl(src))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
