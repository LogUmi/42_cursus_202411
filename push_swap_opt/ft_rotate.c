/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:46:16 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/30 21:50:36 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ra(t_list **a)
{
	t_list	*lst;
	t_list	*first;

	first = *a;
	if (ft_lstsize(*a) < 2)
		return (NULL);
	*a = first->next;
	first->next = 0;
	lst = *a;
	while (lst != 0 && lst->next != 0)
		lst = lst->next;
	lst->next = first;
	return ("ra\n");
}

char	*rb(t_list **b)
{
	t_list	*lst;
	void	*cfirst;

	lst = *b;
	if (ft_lstsize(lst) < 2)
		return (NULL);
	cfirst = lst->next;
	while (lst != 0 && lst->next != 0)
		lst = lst->next;
	(*b)->next = 0;
	lst->next = *b;
	*b = cfirst;
	return ("rb\n");
}

char	*rr(t_list **a, t_list **b)
{
	char	*ca;
	char	*cb;

	ca = ra(a);
	cb = rb(b);
	if (ca == NULL && cb == NULL)
		return (NULL);
	return ("rr\n");
}
