/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:46:16 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/29 19:44:10 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ra(t_list **a)
{
	t_list	*lst;
	void	*cfirst;

	lst = *a;
	if (ft_lstsize(lst) < 2)
		return (NULL);
	cfirst = lst->next;
	while (lst != 0 && lst->next != 0)
		lst = lst->next;
	(*a)->next = 0;
	lst->next = *a;
	*a = cfirst;
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
			write (1, &prt, ft_strlen(prt) + 1);
		if (cmde[i] != 0)
			i++;
	}
}
