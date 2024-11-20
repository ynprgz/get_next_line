/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:39:37 by yaperalt          #+#    #+#             */
/*   Updated: 2024/11/21 00:04:23 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
	Checking if the macro BUFFER_SIZE is not defined.
	Defines it with the value 42. Creating the constant named BUFFER_SIZE with
	value 42.
	#endif ends the #ifndef block, signaling that the conditional directive is
	complete.

	BUFFER_SIZE macro determines the size of the buffer used when reading data
	from a file.
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h> // For open()
# include <unistd.h> // For read(), write(), close()
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);

#endif
