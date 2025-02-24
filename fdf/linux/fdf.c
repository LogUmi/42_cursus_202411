/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:11:12 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/24 22:50:06 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	main(int argc, char **argv)
{
	t_dmlx	vars;

	init_dmlx(&vars);
	if (argc != 2)
		return (error(&vars, "Argument issue (only path/map_filename)", 1));
	map_load(&vars, &argv[1][0], 0, 0);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (error(&vars, "mlx_init failed", 1));
	if (mlx_get_screen_size(vars.mlx, &vars.swidth, &vars.sheight) != 0)
		return (error(&vars, "mlx was unable to detect screen", 1));
	ft_printf("Screen %dx%d detected\n", vars.swidth, vars.sheight);
	vars.win = mlx_new_window(vars.mlx, 1000, 500, &argv[1][0]);
	if (!vars.win)
		return (error(&vars, "mlx_new_window failed", 1));
	mlx_hook(vars.win, 2, 1L << 0, ft_key, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
