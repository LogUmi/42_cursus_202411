/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/27 20:07:21 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include "libft/includes/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

# define XK_ESCAPE 0xff1b
# define DEF_COLOR 0x0000FF00

typedef struct s_map
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
	int				pos;
	void			*previous;
	void			*next;
	void			*side;
	void			*down;
}					t_map;

typedef struct s_dmlx
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	**map;
	void	*tab;
	int		swidth;
	int		sheight;
	int		width;
	int		height;
	double	magn;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zmin;
	double	zmax;
	double	maxdiag;
	double	aaxex;
	double	aaxey;
	double	aaxez;
	double	crefx;
	double	crefy;
	double	crefz;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}			t_dmlx;

typedef struct s_line
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	unsigned int	c1;
	unsigned int	c2;
	int				npoint;
	int				num;
}				t_line;

int		error(t_dmlx *vars, char *msg, int ret);
void	init_dmlx(t_dmlx *vars);
void	map_load(t_dmlx *vars, char *filename, int count, double line);
t_map	*ft_newpoint(double *i, double y, t_dmlx *vars, unsigned int color);
void	ft_mapadd_back(t_map **lst, t_map *new);
void	free_tabfdf(char **tab, t_dmlx *vars);
void	free_map(t_map **lst, t_dmlx *vars);
void	size_img(t_dmlx *vars);
double	direction(double a, double b);
int		intercolor(int color1, int color2, double t);
void	cpy_line(t_dmlx *mlx, t_map *a, t_map *b, t_line *line);
void	draw_lines(t_dmlx *mlx, t_map **map);


void print_t_map(t_map **map);

#endif
