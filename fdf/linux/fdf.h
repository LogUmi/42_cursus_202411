/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/21 17:33:01 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include "mlx_linux/mlx.h"

# define XK_ESCAPE                        0xff1b

typedef struct	s_dmlx 
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_dmlx;


#endif
