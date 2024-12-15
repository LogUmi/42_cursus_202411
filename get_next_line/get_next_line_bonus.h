/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:38:43 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/15 22:36:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# ifndef STATIC_SIZE
#  define STATIC_SIZE 21000
# endif
# if STATIC_SIZE < 0
#  undef STATIC_SIZE
#  define STATIC_SIZE 0
# endif
# if STATIC_SIZE > 21000
#  undef STATIC_SIZE
#  define STATIC_SIZE 21000
# endif

char	*get_next_line(int fd);
char	*ft_strncpygnl(char *src, char *dst, int n, int way);

#endif