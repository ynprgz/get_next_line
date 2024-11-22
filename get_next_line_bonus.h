/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:39:24 by yaperalt          #+#    #+#             */
/*   Updated: 2024/11/22 23:35:39 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*
 $	Checking if the macro BUFFER_SIZE is not defined.
 $	Defines it with the value 42. Creating the constant named BUFFER_SIZE with
 $	value 42.
 $	#endif ends the #ifndef block, signaling that the conditional directive is
 $	complete.
 $
 $	BUFFER_SIZE macro determines the size of the buffer used when reading data
 $	from a file.
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>// For open()
# include <unistd.h>// For read(), write(), close()
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
