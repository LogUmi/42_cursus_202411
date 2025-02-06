/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:50:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/05 17:22:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "push_swap.h"

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

int	ft_debug(t_list **a, t_list **b)
{
	int		*i;
	t_list	*lsta = *a;
	t_list	*lstb = *b;
	int		*j;
	int		k;
	
	while (lsta != 0 || lstb != 0)
	{
		if (lsta != 0)
		{
			i = lsta->content;
			lsta = lsta->next;
			//ft_printf("%p : ", lsta);
			ft_printf("%05i %05i %05i %05i ... ", i[0], i[1], i[2], i[3]);
			k = 0;
			while (k < 32)
				ft_printf(" %i ", i[k++ + 4]);
			ft_printf (" / ");
		}
		else
		{
			ft_printf("%5c %5c %5c %5c ... ", ' ', ' ', ' ', ' ');
			k = 0;
			while (k < 10)
			{	
				ft_printf("   ");
				k++;
			}
			ft_printf (" / ");
		}
		if (lstb != 0)
		{
			j = lstb->content;
			lstb = lstb->next;
			//ft_printf("%p : ", lsta);
			ft_printf("%05i %05i %05i %05i ... ", j[0], j[1], j[2], j[3]);
			k = 0;
			while (k < 32)
				ft_printf(" %i ", i[k++ + 4]);
		}
		else
			ft_printf("%5c %5c %5c %5c ... ", ' ', ' ', ' ', ' ');
		ft_printf("\n");
	}
		ft_printf("%26s%81s\n\n", "A", "B");
		//get_key_press();
	return (0);
}

int	test_pushswap(t_list **a, t_list **b)
{
	char	c = 0;
	int		i = 0;
	
	while (c != 'q')
	{
		c = get_key_press();
		if (c == '3')
		{
			i++;
			ft_printf("%s(cpt = %i)\n", pa(a, b), i);;
		}
		if (c == '4')
		{
			i++;
			ft_printf("%s(cpt = %i)\n", pb(a, b), i);
		}
		if (c == 'e')
		{
			i++;
			ft_printf("%s(cpt = %i)\n", sa(a), i);
		}
		if (c == 'r')
		{	
			i++;
			ft_printf("%s(cpt = %i)\n", sb(b), i);
		}
		if (c == 't')
		{
			i++;
			ft_printf("%s(cpt = %i)\n", ss(a, b), i);
		}
		if (c == 'd')
		{
			i++;
			ft_printf("%s(cpt = %i)\n",ra(a), i);
		}
		if (c == 'f')
		{
			i++;
			ft_printf("%s(cpt = %i)\n",rb(b), i);
		}
		if (c == 'g')
		{
			i++;
			ft_printf("%s(cpt = %i)\n",rr(a, b), i);
		}
		if (c == 'c')
		{
			i++;
			ft_printf("%s(cpt = %i)\n",rra(a), i);
		}
		if (c == 'v')
		{
			i++;
			ft_printf("%s(cpt = %i)\n",rrb(b), i);
		}
		if (c == 'b')
		{
			i++;
			ft_printf("%s(cpt = %i)\n",rrr(a, b), i);
		}
		if( c != 'q')
		{
			testsort(a, b, 0, 0);
			ft_debug(a, b);
		}
	}
	return (0);
}
/* int		ft_debug(t_list **a, t_list **b);
int 	get_key_press();
int		test_pushswap(t_list **a, t_list **b); */