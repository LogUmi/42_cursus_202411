/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:39 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/28 19:20:32 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_debug(t_list **a, t_list **b);
int 	get_key_press();
int		test_pushswap(t_list **a, t_list **b);

static void	ft_lstclear_ps(t_list **lst)
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
	int	i;

	i = 0;
	ft_lstclear_ps(a);
	ft_lstclear_ps(b);
	if (nbr && nbr[0])
	{
		while (nbr[i])
			free(nbr[i++]);
		free(nbr);
	}
	return (0);
}

void	Excmde(t_list **a, t_list **b, char *cmde)
{
	char *prt;
	
	
}

void	startorder(t_list **a, t_list **b)
{
	if (ft_lstsize(a) == 1)
		return;
	if (ft_lstsize(a) == 2)
		if ((*a)->content > (*a)->next->content)
			
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
	b = NULL;
	ft_debug(&a, &b);
	ft_printf("%s\n)");
	test_pushswap(&a, &b);
	
	return (ft_freestack(&a, &b, nbr));
}
