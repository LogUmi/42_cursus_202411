/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:46:11 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/27 22:01:17 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

char	*rra(t_list **a)
{
	t_list	*lst;
	t_list	*plst;
	void	*cfirst;

	lst = *a;
	if (ft_lstsize(lst) < 2)
		return(NULL);
	while (lst != 0 && lst->next->next !=0)
		lst = lst->next;
	plst = lst;
	cfirst = lst->next;
	lst = lst->next;
	plst->next = 0;
	lst->next = *a;
	*a = cfirst;
	return ("rra");
}

char	*rrb(t_list **b)
{
	t_list	*lst;
	t_list	*plst;
	void	*cfirst;

	lst = *b;
	if (ft_lstsize(lst) < 2)
		return(NULL);
	while (lst != 0 && lst->next->next !=0)
		lst = lst->next;
	plst = lst;
	cfirst = lst->next;
	lst = lst->next;
	plst->next = 0;
	lst->next = *b;
	*b = cfirst;return ("rrb");
}

char	*rrr(t_list **a, t_list **b)
{	
	char	*ca;
	char	*cb;
	
 	ca = rra(a);
	cb = rrb(b);
	if (ca == NULL && cb == NULL)
		return (NULL);
	return ("rrr");
}