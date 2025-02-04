/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:39 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/04 01:16:46 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_debug(t_list **a, t_list **b);
int		get_key_press(void);
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

void	startorder(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 1)
		return ;
	if (ft_lstsize(*a) == 2)
		algo_2(a, b);
	if (ft_lstsize(*a) == 3)
		algo_3(a, b);
	if (ft_lstsize(*a) > 3)
		algo_radix(a, b);
	//ft_debug(a, b);
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
	if (testsort(&a, &b, 0, 0) == 0)
		return (ft_freestack(&a, &b, nbr)); 
	//ft_debug(&a, &b);
	//ft_printf("\n)");
	//test_pushswap(&a, &b);
	startorder(&a, &b);
	return (ft_freestack(&a, &b, nbr));
}
