/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:50:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/27 21:48:41 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "push_swap.h"

int	ft_debug(t_list **a, t_list **b)
{
	int		*i;
	t_list	*lsta = *a;
	t_list	*lstb = *b;
	int		*j;
	
	while (lsta != 0 || lstb != 0)
	{
		if (lsta != 0)
		{
			i = lsta->content;
			lsta = lsta->next;
			ft_printf("%05i %05i / ", i[0], i[1]);
		}
		else
			ft_printf("%5c %5c / ", ' ', ' ');
		if (lstb != 0)
		{
			j = lstb->content;
			lstb = lstb->next;
			ft_printf("%05i %05i\n", j[0], j[1]);
		}
		else
			ft_printf("%5c %5c\n", ' ', ' ');
	}
	return (0);
}

int get_key_press() 
{
    struct termios oldt, newt;
    int ch;

    // Obtenir les paramètres actuels du terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    // Désactiver le mode canonique et l'écho
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();  // Lire un caractère

    // Restaurer les paramètres du terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int	test_pushswap(t_list **a, t_list **b)
{
	char c = 0;

	while (c != 'q')
	{
		c = get_key_press();
		if (c == '3')
			ft_printf("%s\n", pa(a, b));
		if (c == '4')
			ft_printf("%s\n", pb(a, b));
		if (c == 'e')
			ft_printf("%s\n", sa(a));
		if (c == 'r')
			ft_printf("%s\n", sb(b));
		if (c == 't')
			ft_printf("%s\n", ss(a, b));
		if (c == 'd')
			ft_printf("%s\n",ra(a));
		if (c == 'f')
			ft_printf("%s\n",rb(b));
		if (c == 'g')
			ft_printf("%s\n",rr(a, b));
		if (c == 'c')
			ft_printf("%s\n",rra(a));
		if (c == 'v')
			ft_printf("%s\n",rrb(b));
		if (c == 'b')
			ft_printf("%s\n",rrr(a, b));
		if( c != 'q')
			ft_debug(a, b);
	}
	return (0);
	
}