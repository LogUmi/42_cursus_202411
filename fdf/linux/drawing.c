/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:30:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/27 04:53:29 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_dmlx *mlx, t_line *l)
{
	char				*dst;
	unsigned long long	ofst;
	unsigned int		color;
	
	ofst = (unsigned long long)(l->y1 * mlx->llen + (l->x1 * (mlx->bpp / 8)));
    color = intercolor(l->c1, l->c2, (double)(l->num / l->npoint));
	if (l->x1 < 0 || l->y1 < 0 || l->x1 >= mlx->width || l->y1 >= mlx->height)
        return;
    dst = mlx->addr + ofst;
    *(unsigned int*)dst = color;
}

void	correct_point(t_dmlx *mlx, t_line *l)
{
	l->x1 = floor(l->x1 * mlx->magn + mlx->crefx);
	l->x2 = floor(l->x2 * mlx->magn + mlx->crefx);
	l->y1 = floor(l->y1 * mlx->magn + mlx->crefy);
	l->y2 = floor(l->y2 * mlx->magn + mlx->crefy);
}

void	draw_line(t_dmlx *mlx, t_line *l)
{
	double dl[6];

    correct_point(mlx, l);
	dl[0] = fabs(l->x2 - l->x1);
	dl[1] = fabs(l->y2 - l->y1);
	dl[2] = direction (l->x1, l->x2);
	dl[3] = direction(l->y1, l->y2);
	dl[4] = dl[0] - dl[1];
	while (l->x1 != l->x2 || l->y1 != l->y2)
    {
        put_pixel(mlx, l);
        dl[5] = 2 * dl[4];
        if (dl[2] > -dl[1])
		{
			dl[4] -= dl[1];
			l->x1 += dl[2];
		}
        if (dl[5] < dl[0])
		{
			dl[4] += dl[0];
			l->y1 += dl[3];
		}
	}
}

void	draw_lines(t_dmlx *mlx, t_map **map)
{
	t_map	*a;
	t_line	line;

	a = *map;
	while(a)
	{
		if (a->side != 0)
		{
			cpy_line(a, a->side, &line);
			draw_line(mlx, &line);
		}
	}
		
		a = a->next;
}


/* draw line
dl[0] = distance_x = abs(b.x - a.x)
dl[1] = distance_y = abs(b.y - a.y)
dl[2] = direction_x = 1 if (a.x < b.x) else -1
dl[3] = direction_y = 1 if (a.y < b.y) else -1
dl[4] = gap = distance_x - distance_y;
dl[5] = indicateur de changement d'axe = 2 * gap
*/