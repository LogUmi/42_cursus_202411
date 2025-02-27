/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:23:43 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/26 19:27:31 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_dmlx(t_dmlx *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;
	vars->map = NULL;
	vars->tab = NULL;
	vars->swidth = 0;
	vars->sheight = 0;
	vars->xmin = 0;
	vars->xmax = 0;
	vars->ymin = 0;
	vars->ymax = 0;
	vars->zmin = 0;
	vars->zmax = 0;
	vars->aaxex = 0;
	vars->aaxey = 0;
	vars->aaxez = 0;
	vars->crefx = 0;
	vars->crefy = 0;
	vars->crefz = 0;
}

void	free_tabfdf(char **tab, t_dmlx *vars)
{
	int	i;

	i = 0;
	if (**tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
		vars->tab = NULL;
	}
}

void	free_map(t_map **lst, t_dmlx *vars)
{
	t_map	*tlst;
	t_map	*slst;

	tlst = *lst;
	while (tlst)
	{
		slst = tlst->next;
		free(tlst);
		tlst = slst;
	}
	vars->map = NULL;
}

t_map	*ft_newpoint(double x, double y, double z, unsigned int color)
{
	t_map	*nc;

	nc = malloc(sizeof(t_map));
	if (nc == 0)
		return (0);
	nc->x = x;
	nc->y = y;
	nc->z = z;
	nc->color = color;
	nc->previous = 0;
	nc->next = 0;
	nc->side = 0;
	nc->down = 0;
	nc->pos = 0;
	return (nc);
}

void	ft_mapadd_back(t_map **lst, t_map *new)
{
	t_map	*tlst;

	if (!lst || !new)
		return ;
	tlst = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (tlst->next != 0)
		tlst = tlst->next;
	tlst->next = new;
	new->previous = tlst;
	return ;
}
