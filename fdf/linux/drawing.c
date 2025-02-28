/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:30:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/27 23:02:49 by lgerard          ###   ########.fr       */
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
	l->num++;
	if (l->x1 < 0 || l->y1 < 0 || l->x1 >= mlx->width || l->y1 >= mlx->height)
        return;
    dst = mlx->addr + ofst;
    *(unsigned int*)dst = color;
}

void	draw_line(t_dmlx *mlx, t_line *l)
{
	int dl[6];

	dl[0] = abs(l->x2 - l->x1);
	dl[1] = abs(l->y2 - l->y1);
	dl[2] = direction (l->x1, l->x2);
	dl[3] = direction(l->y1, l->y2);
	dl[4] = dl[0] - dl[1];
	dl[5] = 2 * dl[4];
	//printf("x1 %d, y1 %d, x2 %d, y2 %d, c1 %u, c2 %u npoint %d, num %d\n", l->x1, l->y1, l->x2, l->y2, l->c1, l->c2, l->npoint, l->num);
	while (l->x1 != l->x2 || l->y1 != l->y2)
    {
		//printf("x1 %d, y1 %d, num %d, dx %d, dy %d, vx %d, vy %d, gap %d, flag %d\n", l->x1, l->y1,l->num, dl[0], dl[1], dl[2], dl[3], dl[4], dl[5]);
		put_pixel(mlx, l);
		if (dl[5] > -dl[1])
		{
			dl[4] -= dl[1];
			l->x1 += dl[2];
		}
		if (dl[5] < dl[0])
		{
			dl[4] += dl[0];
			l->y1 +=dl[3];
		}
		dl[5] = 2 * dl[4];
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
			cpy_line(mlx, a, (t_map *)a->side, &line);
			draw_line(mlx, &line);
		}
		if (a->down != NULL)
		{
			cpy_line(mlx, a, (t_map *)a->down, &line);
			draw_line(mlx, &line);
		}
		a = a->next;
	}
}


/* draw line
dl[0] = distance_x = abs(b.x - a.x)
dl[1] = distance_y = abs(b.y - a.y)
dl[2] = direction_x = 1 if (a.x < b.x) else -1
dl[3] = direction_y = 1 if (a.y < b.y) else -1
dl[4] = gap = distance_x - distance_y;
dl[5] = indicateur de changement d'axe = 2 * gap
*/