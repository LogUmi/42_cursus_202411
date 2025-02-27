/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:11:55 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/27 04:39:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_isometric(t_map **map)
{
	double	anc_x;
	double	anc_y;
	t_map	*a;

	a = *map;
	while (a)
	{
		anc_x = a->x;
		anc_y = a->y;
		a->x = (anc_x - anc_y) * cos(0.523599);
		a->y = (anc_x + anc_y) * sin(0.523599) - a->z;
		a = a->next;
	}
}

void	set_side_down(t_map *a, t_map *b)
{
	b = a->next;
	if (b->y == a->y)
		a->side = b;
	else
		a->side = NULL;
	b = a;
	a->down = NULL;
	while (b)
	{
		if (a->x == b->x && a->y < b->y)
		{
			a->down = b;
			b = NULL;
		}
		else
			b = b->next;
	}
}

void	set_map(t_map **map, t_map *a, t_map *b)
{
	a = *map;
	while (a)
	{
		if (a->next != NULL)
			set_side_down(a, b);
		else
		{
			a->side = NULL;
			a->down = NULL;
		}
		a = a->next;
	}
}

void	get_magn(t_dmlx *vars)
{
	int	little;
	int	div;

	if (vars->swidth < vars->sheight)
		little = vars->swidth;
	else
		little = vars->sheight;
	div = (double)little / vars->maxdiag;
	if (div >= 1)
		vars->magn = floor(div * 0.75);
	else
		vars->magn = div - 0.1;
	vars->height = floor(vars->maxdiag * vars->magn);
	vars->width = floor(vars->maxdiag * vars->magn);
	vars->crefx = floor(((vars->width - vars->xmax * vars->magn) / 2));
	vars->crefy = floor(((vars->height - vars->ymax * vars->magn) / 2));
}

void	size_img(t_dmlx *vars)
{
	double	zdiag;
	double	zuse;

	zdiag = 0;
	zuse = 0;
	vars->maxdiag = ceil(sqrt(pow(vars->xmax, 2) + pow(vars->ymax, 2)));
	if (vars->zmax < 0)
		zuse = (vars->zmin * -1) + vars->zmax;
	else
		zuse = vars->zmax - vars->zmin;
	zdiag = ceil(sqrt(pow(vars->xmax, 2) + pow(zuse, 2)));
	if (zdiag > vars->maxdiag)
		vars->maxdiag = zdiag;
	zdiag = ceil(sqrt(pow(vars->ymax, 2) + pow(zuse, 2)));
	if (zdiag > vars->maxdiag)
		vars->maxdiag = zdiag;
	get_magn(vars);
	set_map((t_map **)vars->map, 0, 0);
}
