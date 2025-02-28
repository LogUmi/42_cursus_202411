/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:11:55 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/28 00:31:36 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <assert.h>

void	set_isometric(t_map **map, double new_x, double new_y, t_dmlx *vars)
{
	t_map	*a;

	a = *map;
	while (a)
	{
		new_x = (a->x - a->y) * cos(0.733038);
		new_y = (a->x + a->y) * sin(0.733038) - a->z / 12;
		//new_x = (a->x - a->y) * sqrt(2) /2;
		//new_y = a->z * sqrt(2) / 3 - (a->x + a->y) / sqrt(6) 0.523599;
		a->x = new_x;
		a->y = new_y;
		if (a->x < vars->xmin)
			vars->xmin = a->x;
		if (a->y < vars->ymin)
		vars->ymin = a->y;
			if (a->z < vars->zmin)
		vars->zmin = a->z;
			if (a->x > vars->xmax)
		vars->xmax = a->x;
			if (a->y > vars->ymax)
		vars->ymax = a->y;
			if (a->z > vars->zmax)
		vars->zmax = a->z;
		a = a->next;
	}
}

void	set_side_down(t_map *a, t_map *b)
{
	if (b->y == a->y)
		a->side = b;
	else
		a->side = NULL;
	b = a;
	a->down = NULL;
	while (b)
	{
		if (a->x == b->x && a->y == (b->y - 1))
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
		{
			b = a->next;
			set_side_down(a, b);
		}
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
	vars->height = (vars->maxdiag * vars->magn);
	vars->width = (vars->maxdiag * vars->magn);
	vars->crefx = (((vars->width - vars->xmax * vars->magn)/1.35));
	vars->crefy = (((vars->height - vars->ymax * vars->magn)/1.8));
}
void	size_img(t_dmlx *vars)
{
	double	zdiag;
	double	zuse;

	zdiag = 0;
	zuse = 0;
	vars->xmin = 0;
	vars->ymin = 0;
	vars->xmax = 0;
	vars->xmin = 0;
	vars->zmin = 0;
	vars->zmax = 0;
	set_map(vars->map, 0, 0);
	set_isometric(vars->map, 0, 0, vars);
	vars->maxdiag = ceil(sqrt(pow(fabs(vars->xmax - vars->xmin), 2) + pow(fabs(vars->ymax -vars->ymin), 2)));
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
}
