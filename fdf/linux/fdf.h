/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/02 02:19:49 by lgerard          ###   ########.fr       */
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
# define DEF_COLOR 0x00FFFFFF
# define DEF_TOPCOLOR 0x00E783E7

typedef struct s_map
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
	void			*next;
	void			*side;
	void			*down;
}					t_map;

typedef struct s_zpos
{
	double	z;
	int		pos;
	void	*next;
}			t_zpos;

typedef struct s_dmlx
{
	void			*mlx;
	void			*win;
	void			*img;
	t_map			**map;
	t_zpos			**zpos;
	void			*tab;
	int				nz;
	int				swidth;
	int				sheight;
	int				width;
	int				height;
	double			magn;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			zmin;
	double			zmax;
	double			maxdiag;
	int				color;
	unsigned int	lowdefcol;
	unsigned int	optdefcol;
	unsigned int	topdefcol;
	double			iangle;
	double			zangle;
	double			yangle;
	int				c42;
	double			zfact;
	double			crefx;
	double			crefy;
	char			*addr;
	int				bpp;
	int				llen;
	int				endian;
}					t_dmlx;

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
void	map_get(t_dmlx *mlx, char *filename);
void	set_map(t_map **map, t_map *a, t_map *b);
t_zpos	*ft_newzpos(double z, t_dmlx *mlx);
void	free_zpos(t_zpos **lst, t_dmlx *vars);
void	zpos_add_back(t_zpos **lst, t_zpos *new);
void	list_zpos(t_dmlx *mlx, double z);
int		z_inlist(t_zpos **zpos, double z);
int		pre_featuring_0(t_dmlx *mlx, char *f, int *i, int len);
int		pre_featuring(t_dmlx *mlx, char *f, int i, int len);
int		zpos_sort(t_zpos **zpos, int i, double cpz);


void print_t_map(t_map **map);

#endif
