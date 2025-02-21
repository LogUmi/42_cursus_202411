/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:11:12 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/21 17:34:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(t_dmlx *vars, char *msg, int ret)
{
	if (*msg)
		ft_printf("%s\n", msg);
	if (vars->win != 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (vars->mlx != 0)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit (ret);
	
}

int	ft_close(int keycode, t_dmlx *vars)
{
	ft_printf("keycode : %d\n", keycode);
	if (keycode == XK_ESCAPE)
		return (error(vars, "Regular end of session", 0));
	else
		return (0);

}

int	main(void)
{
	t_dmlx	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (error(&vars, "mlx_init failed", 1));
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	if (!vars.win)
		return (error(&vars, "mlx_new_window failed", 1));
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}