/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:39 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/24 19:03:25 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_debug(t_list **a, int **nbr)
{
	int		i;
	t_list	*lst;
	int		*j;

	i = 0;
	lst = *a;
	while (lst != 0)
	{
		j = lst->content;
		ft_printf("%05i %05i / %05i %05i\n", j[0], j[1], nbr[i][0], nbr[i][1]);
		lst = lst->next;
		i++;
	}
	return (0);
}

void	ft_lstclear_ps(t_list **lst)
{
	t_list	*tlst;
	t_list	*slst;

	tlst = *lst;
	while (tlst != 0)
	{
		slst = tlst->next;
		
		free(tlst);
		tlst = slst;
	}
	*lst = 0;
	return ;
}

int	ft_freestack(t_list **a, t_list **b, int **nbr)
{
	ft_lstclear_ps(a);
	ft_lstclear_ps(b);
	//ft_freenbr(nbr);
	return (0);
}

int	setstack(int **nbr, int i)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(nbr[i--]);
	if (!a)
		return (ft_freenbr(nbr));
	while (i > -1)
	{
		b = ft_lstnew(nbr[i--]);
		if (!b)
			return (ft_freestack(&a, &b, nbr));
		ft_lstadd_front(&a, b);
	}
	ft_debug(&a, nbr);
	return (ft_freestack(&a, &b, nbr));
}
