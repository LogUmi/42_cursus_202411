/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:55:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/06 19:31:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_debug(t_list **a, t_list **b);

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
void	algo_radix_1(t_list **a, t_list **b, char * cmde, int j)
{
	t_list	*lst;
	int		*i;
	int		l[2][2];

	l[0][0] = 0;
	while (l[0][0] != -1)
	{
		l[0][0] = 0;
		l[0][1] = 0;
		l[1][0] = 0;
		l[1][1] = 0;
		lst = *a;
		while (lst != 0 && l[0][0] == 0)
		{
			i = lst->content;
			lst = lst->next;	
			if (i[7 + j] != 1)
			{
					l[0][0] = i[2] + 1;
					l[0][1] = ft_lstsize(*a) - i[2] + 1;
			}
		}
		while (lst != 0)
		{
			i = lst->content;
			lst = lst->next;
			if (i[7 + j] != 1)
			{
					l[1][0] = i[2] + 1;
					l[1][1] = ft_lstsize(*a) - i[2] + 1;
			}
		}
		if (l[0][0] == l[1][0] && l[0][0] != 0)
		{
			if (l[0][0] <= l[0][1])
			{
				while ((l[0][0]) > 1)
				{
					addcmde(cmde, "ra");
					l[0][0]--;				
				}
				addcmde(cmde, "pb");
			}
			else if (l[0][1] < l[0][0])
			{
				while ((l[0][1]) > 1)
				{
					addcmde(cmde, "rra");
					l[0][1]--;				
				}
				addcmde(cmde, "pb");
			}
			l[0][0] = -1;
		}
		else if (l[0][0] != l[1][0] && l[0][0] != 0)
		{
			if (l[0][0] <= l[1][1])
			{
				while ((l[0][0]) > 1)
				{
					addcmde(cmde, "ra");
					l[0][0]--;				
				}
				addcmde(cmde, "pb");
			}
			else if (l[1][1] < l[0][0])
			{
				while ((l[1][1]) > 1)
				{
					addcmde(cmde, "rra");
					l[1][1]--;				
				}
				addcmde(cmde, "pb");
			}	
		}
		if (l[0][0] == 0)
			l[0][0] = -1;
		else
		{
			excmde(a, b, cmde);
			cmde[0] = 0;
			testsort(a, b, 0, 0);
		}
	}
	//ft_debug(a, b);
	lst = *b;
	while (lst != 0)
	{
		addcmde(cmde, "pa");
		lst = lst->next;
	}
	excmde(a, b, cmde);
	cmde[0] = 0;
	//ft_debug(a, b);
	testsort(a, b, 0, 0);
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
		if (i[7 + j] == 1)
			cmde = addcmde(cmde, "ra");
		else
			cmde = addcmde(cmde, "pb");
	}
	excmde(a, b, cmde);
	cmde[0] = 0;
	ft_debug(a, b);
	lst = *b;
	while (lst != 0)
	{
		addcmde(cmde, "pa");
		lst = lst->next;
	}
	excmde(a, b, cmde);
	cmde[0] = 0;
	ft_debug(a, b);
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
			algo_radix_1(a, b, cmde, j);
		j++;
	}
	free(cmde);
}
 