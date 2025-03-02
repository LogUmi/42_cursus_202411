/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 02:59:48 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/01 23:15:32 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		direction(double a, double b)
{
	if (a < b)
    	return (1);
	if (a > b)
    	return (-1);
	return (0);
}

void	cpy_line(t_dmlx *mlx,t_map *a, t_map *b, t_line *l)
{
	double	varx;
	double 	vary;

	varx = a->x;
	vary = a->y;
	l->x1 = varx * mlx->magn + mlx->crefx;
	l->y1 = vary * mlx->magn + mlx->crefy;
	if (a->color != b->color && a->z == 0 && mlx->c42 != 0)
		l->c1 = mlx->optdefcol;
	else
		l->c1 = a->color;
	varx = b->x;
	vary = b->y;
	l->x2 = varx * mlx->magn + mlx->crefx;
	l->y2 = vary * mlx->magn + mlx->crefy;
	if (b->color != a->color && b->z == 0 && mlx->c42 != 0)
		l->c2 = mlx->optdefcol;
	else
		l->c2 = b->color;
	if(abs(l->x2 - l->x1) > abs(l->y2 - l->y1))
		l->npoint = abs(l->x2 - l->x1) + 1;
	else
		l->npoint = abs(l->y2 - l->y1) + 1;
	l->num = 0;
}

int intercolor(int color1, int color2, double n)
{
    int	r[3];
	int	g[3];
	int	b[3];
	
	r[1] = (color1 >> 16) & 0xFF;
    g[1] = (color1 >> 8)  & 0xFF;
    b[1] = (color1)       & 0xFF;
    r[2] = (color2 >> 16) & 0xFF;
    g[2] = (color2 >> 8)  & 0xFF;
    b[2] = (color2)       & 0xFF;

    r[0] = (int)(r[1] + n * (r[2] - r[1]));
    g[0] = (int)(g[1] + n * (g[2] - g[1]));
  	b[0] = (int)(b[1] + n * (b[2] - b[1]));

    return (r[0] << 16) | (g[0] << 8) | b[0];
}