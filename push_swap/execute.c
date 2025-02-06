/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:03:20 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/04 12:23:20 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	testsort(t_list **a, t_list **b, int j, int k)
{
	t_list	*lst;
	int	*i;
	
	lst = *a;
	while (lst != 0)
	{
		i = lst->content;
		i[2] = j++;
		i[3] = -1;
		if (i[2] == i[1])
			k++;			
		lst = lst->next;
	}
	lst = *b;
	j = 0;
	while (lst != 0)
	{
		i = lst->content;
		i[3] = j++;						
		i[2] = -1;
		lst = lst->next;
	}
	return (k - ft_lstsize(*a) - ft_lstsize(*b));
}

static void	exucmde_1(t_list **a, t_list **b, char *cmde, char **prt)
{
	if (ft_strncmp(cmde, "sa", 2) == 0)
		(*prt) = sa(a);
	if (ft_strncmp(cmde, "sb", 2) == 0)
		(*prt) = sb(b);
	if (ft_strncmp(cmde, "ss", 2) == 0)
		(*prt) = ss(a, b);
	if (ft_strncmp(cmde, "pa", 2) == 0)
		(*prt) = pa(a, b);
	if (ft_strncmp(cmde, "pb", 2) == 0)
		(*prt) = pb(a, b);
	if (ft_strncmp(cmde, "ra", 2) == 0)
		(*prt) = ra(a);
	if (ft_strncmp(cmde, "rb", 2) == 0)
		(*prt) = rb(b);
	if (ft_strncmp(cmde, "rr", 2) == 0)
		(*prt) = rr(a, b);
}
char	*addcmde(char *cmde, char *src)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!src)
		return (cmde);
	while (cmde[i] != 0)
		i++;
	if (i > 0)
		cmde[i++] = 32;
	while (src[j] != 0)
		cmde[i++] = src[j++];
	cmde[i] = 0;
	return (cmde);
}
static void	exucmde(t_list **a, t_list **b, char *cmde, char **prt)
{
	if (ft_strlen(cmde) == 3)
	{
		if (ft_strncmp(cmde, "rra", 3) == 0)
			(*prt) = rra(a);
		if (ft_strncmp(cmde, "rrb", 3) == 0)
			(*prt) = rrb (b);
		if (ft_strncmp(cmde, "rrr", 3) == 0)
			(*prt) = rrr(a, b);
	}
	else
		exucmde_1(a, b, cmde, prt);
}

void	excmde(t_list **a, t_list **b, char *cmde)
{
	char	*prt;
	char	ucmde[10];
	int		i;
	int		j;

	prt = NULL;
	i = 0;
	while (cmde[i] != 0)
	{
		j = 0;
		while (cmde[i] != 32 && cmde[i] != 0)
			ucmde[j++] = cmde[i++];
		ucmde[j] = 0;
		exucmde(a, b, ucmde, &prt);
		if (prt != NULL)
			ft_printf ("%s", prt);
		if (cmde[i] != 0)
			i++;
	}
}
