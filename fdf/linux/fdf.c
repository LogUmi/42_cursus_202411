/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:11:12 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/27 04:47:10 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_struct(t_dmlx *vars);

int	error(t_dmlx *vars, char *msg, int ret)
{
	if (*msg)
		ft_printf("%s\n", msg);
	if (vars->tab != NULL)
		free_tabfdf((char **)vars->tab, vars);
	if (vars->map != 0)
		free_map((t_map **)vars->map, vars);
	if (vars->img != 0)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win != 0)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx != 0)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit (ret);
}

static int	ft_close(t_dmlx *vars)
{
	return (error(vars, "Regular end of session on mouse command", 0));
}

static int	ft_key(int keycode, t_dmlx *vars)
{
	ft_printf("keycode : %d\n", keycode);
	if (keycode == XK_ESCAPE)
		return (error(vars, "Regular end of session on esc key press", 0));
	else
		return (0);
}

void	main_suite(t_dmlx *mlx)
{
	print_struct(mlx);
	draw_lines(mlx,(t_map **)mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 1L << 0, ft_key, mlx);
	mlx_hook(mlx->win, 17, 0, ft_close, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_dmlx	mlx;
	char	*s;

	init_dmlx(&mlx);
	if (argc != 2)
		return (error(&mlx, "Argument issue (only path/map_filename)", 1));
	s = &argv[1][0];
	map_load(&mlx, s, 0, 0);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (error(&mlx, "mlx_init failed", 1));
	if (mlx_get_screen_size(mlx.mlx, &mlx.swidth, &mlx.sheight) != 0)
		return (error(&mlx, "mlx was unable to detect screen", 1));
	ft_printf("Screen %dx%d detected\n", mlx.swidth, mlx.sheight);
	size_img(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, s);
	if (!mlx.win)
		return (error(&mlx, "mlx_new_window failed", 1));
	printf ("Windows %dx%d opended\n", mlx.width, mlx.height);
	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	if (!mlx.img)
		return (error(&mlx, "mlx_new_image failed", 1));
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.llen, &mlx.endian);
	main_suite(&mlx);
	return (0);
}
