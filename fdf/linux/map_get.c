/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:36:40 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/01 18:46:56 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pre_featuring(t_dmlx *mlx, char *filename, int i, int len)
{
	
	mlx->lowdefcol = DEF_COLOR;
	mlx->topdefcol = DEF_TOPCOLOR;
	mlx->iangle = 0.523598776;
	mlx->zangle = 4.71238898;
	mlx->zfact = 1;
	if (ft_strnstr(filename, "mars.fdf", len) != 0)
	{
		mlx->lowdefcol = 0x00600000;
		mlx->topdefcol = 0x00FF0000;
		i++;
	}
	if (ft_strnstr(filename, "42.fdf", len) != 0)
	{
		mlx->iangle = 0.733038286;
		mlx->zangle = 0;
		mlx->zfact = 10;
		i++;
	}
	return (i);
}

void	center_ref(t_dmlx *mlx, t_map **map, double xmid, double ymid)
{
	t_map	*a;
	
	a = *map;
	xmid = ceil(fabs(mlx->xmax - mlx->xmin) / 2);
	ymid = ceil(fabs(mlx->ymax - mlx->ymin) / 2);
	while (a)
	{
		a->x -= xmid;
		a->y -= ymid;
		a = a->next;
	}
}

void	set_zcolor(t_dmlx *mlx, t_map **map)
{
	t_map			*a;
	int 			zlen;
	unsigned int	col1;
	unsigned int	col2;
	
	a = *map;
	col1 = mlx->lowdefcol;
	col2 = mlx->topdefcol;
	printf("Applying this fdf colors defintion (no colors in map)\n");
	zlen = fabs(mlx->zmax - mlx->zmin);
	while (a)
	{
		if (a->z != mlx->zmin && a->z != mlx->zmax)
			a->color = intercolor(col1, col2, a->z / zlen);
		if (a->z == mlx->zmin)
			a->color = col1;
		if (a->z == mlx->zmax)		
			a->color = col2;
		a = a->next;
	}
}

void	map_get(t_dmlx *mlx, char *filename)
{
	if (pre_featuring(mlx, filename, 0, ft_strlen(filename)) == 0)
		ft_printf("Default prefeature applied\n");
	else
		ft_printf("Special prefeature detected and applied\n");
	ft_printf("Loading map ... ");
	map_load(mlx, filename, 0, 0);
	ft_printf("done\n");
	set_map(mlx->map, 0, 0);
	center_ref(mlx, mlx->map, 0, 0);
	if (mlx->color == 0)
		set_zcolor(mlx, mlx->map);
	else
		printf("Applying colors definition detected in map\n");
}
/* 
30°  = 0.523598776
42°  = 0.733038286
45°  = 0.785398163
60°  = 1.047197551
90°  = 1.570796327
120° = 2.094395102
150° = 2.617993878
180° = 3.141592654
210° = 3.665191429
240° = 4.188790205
270° = 4.71238898
300° = 5.235987756
330° = 5.759586532
360° = 6.283185307
*/