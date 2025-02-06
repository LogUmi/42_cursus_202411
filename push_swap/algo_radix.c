/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:55:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/05 14:36:12 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algo_radix_test(int index, int i)
{
	if (index >= 2)
	{
		i = algo_radix_test(index / 2, i);
		i++;
	}
	if (index < 2)
		i = 0;
	return (i);
}
void	algo_radix_0(t_list **a, t_list **b, char * cmde, int j)
{
	t_list	*lst;
	int		*i;
	
	lst = *a;
	while (lst != 0)
	{
		i = lst->content;
		lst = lst->next;
		if (i[4 + j] == 1)
			cmde = addcmde(cmde, "ra");
		else
			cmde = addcmde(cmde, "pb");
	}
	excmde(a, b, cmde);
	cmde[0] = 0;
	lst = *b;
	while (lst != 0)
	{
		addcmde(cmde, "pa");
		lst = lst->next;
	}
	excmde(a, b, cmde);
	cmde[0] = 0;
}

void	algo_radix(t_list **a, t_list **b)
{
	int		i;
	int		j;
	char	*cmde;

	i = 0;
	j = 0;
	cmde = calloc(sizeof(char), ft_lstsize(*a) * 4  + 1);
	if (!cmde)
		return ;
	while (j <= algo_radix_test(ft_lstsize(*a),0))
	{
			algo_radix_0(a, b, cmde, j);
		j++;
	}
	free(cmde);
}
 