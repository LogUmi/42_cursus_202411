/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:15:47 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/08 23:19:52 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_strlenf(const char *str);
int		ft_putstrf(const char *str);
int		ft_printchar(int i);
int		ft_printstr(const char *str);
int		ft_printint(int i);
int		ft_putnsbase(unsigned int i, char *bs);
int		ft_putnbrullbase(unsigned long long i, char *bs);
int		ft_printpointer(void *p, char *bs);
#endif