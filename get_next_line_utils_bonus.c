/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:39:26 by yaperalt          #+#    #+#             */
/*   Updated: 2024/11/20 23:42:54 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest = malloc(sizeof(char ) * (src_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, src_len + 1);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (len + 1));
	if (!strjoin)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		strjoin[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		strjoin[j++] = s2[i++];
	strjoin[j] = '\0';
	return (strjoin);
}

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	*str_p;

	i = 0;
	str_p = (unsigned char *)str;
	while (str_p[i] != '\0')
	{
		if (str_p[i] == (unsigned char)c)
			return ((char *)&str_p[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)&str_p[i]);
	}
	return (0);
}
