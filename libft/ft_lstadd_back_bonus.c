/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:30:51 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/27 14:00:11 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tlst;

	tlst = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (tlst->next !=0)
		tlst = tlst->next;
	tlst->next = new;
	new->next = 0;
	return ;
}