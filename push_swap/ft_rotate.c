/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:46:16 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/28 15:35:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ra(t_list **a)
{
t_list	*lst;
void	*cfirst;

lst = *a;
if (ft_lstsize(lst) < 2)
	return(NULL);
cfirst = lst->next;
while (lst != 0 && lst->next !=0)
	lst = lst->next;
(*a)->next = 0;
lst->next = *a;
*a = cfirst;
return ("ra");
}

char	*rb(t_list **b)
{
t_list	*lst;
void	*cfirst;

lst = *b;
if (ft_lstsize(lst) < 2)
	return(NULL);
cfirst = lst->next;
while (lst != 0 && lst->next !=0)
	lst = lst->next;
(*b)->next = 0;
lst->next = *b;
*b = cfirst;
return ("rb");
}

char	*rr(t_list **a, t_list **b)
{	
	char	*ca;
	char	*cb;
	
 	ca = ra(a);
	cb = rb(b);
	if (ca == NULL && cb == NULL)
		return (NULL);
	return ("rr");
}

