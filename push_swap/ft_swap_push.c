/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:45:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/27 21:41:53 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_list **a)
{
	t_list	*lst;
	void	*cfirst;
	
	lst = *a;
	if (ft_lstsize(lst) < 2)
		return (NULL);
	cfirst = lst->content;
	while (lst != 0 && lst->next != 0)
		lst = lst->next;
	(*a)->content = lst->content;
	lst->content = cfirst;
	return ("sa");
}

char	*sb(t_list **b)
{
	t_list	*lst;
	void	*cfirst;
	
	lst = *b;
	if (ft_lstsize(lst) < 2)
		return (NULL);
	cfirst = lst->content;
	while (lst != 0 && lst->next != 0)
		lst = lst->next;
	(*b)->content = lst->content;
	lst->content = cfirst;		
	return ("sb");
}

char	*ss(t_list **a, t_list **b)
{
	char	*ca;
	char	*cb;
	
	ca = sa(a);
	cb = sb(b);
	if (ca == NULL && cb == NULL)
		return (NULL);
	return ("ss");
}

char	*pa(t_list **a, t_list **b)
{
	void	*nfirsta;
	void	*nfirstb;
	
	if (ft_lstsize(*b) == 0)
		return (NULL);
	if (ft_lstsize(*b) < 2)
		nfirstb = 0;
	else
		nfirstb = (*b)->next;
	if (ft_lstsize(*a) == 0)
		nfirsta = 0;
	else
		nfirsta = (*a);
	(*b)->next = nfirsta;
	(*a) = *b;
	(*b) = nfirstb;	
	return ("pa");	
}

char	*pb(t_list **a, t_list **b)
{
	void	*nfirsta;
	void	*nfirstb;
	
	if (ft_lstsize(*a) == 0)
		return (NULL);
	if (ft_lstsize(*a) < 2)
		nfirsta = 0;
	else
		nfirsta = (*a)->next;
	if (ft_lstsize(*b) == 0)
		nfirstb = 0;
	else
		nfirstb = (*b);
	(*a)->next = nfirstb;
	(*b) = *a;
	(*a) = nfirsta;	
	return ("pb");
}