/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:39:35 by yaperalt          #+#    #+#             */
/*   Updated: 2024/11/23 02:08:37 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
 $ This function takes a fd and the buffer used to store the content,
 $ appending its content until a newline('\n') is found.
 $ If there are no bytes to be read(read() returns -1), we free the pointer
 $ and return NULL.
 $ ft_strjoin is used to copy the content from the temp variable to the buffer.
 */

char	*ft_read_fd(int fd, char *buffer)
{
	char	*temp;
	int		bytes_count;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_count = 1;
	while (!ft_strchr(buffer, '\n') && (bytes_count != 0))
	{
		bytes_count = read(fd, temp, BUFFER_SIZE);
		if (bytes_count < 0)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		temp[bytes_count] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

/*
 $ We allocate memory for the size of the buffer + 2, so we have space for '\n'
 $ if it's present and '\0' to end it.
 */
char	*ft_get_actual_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i += 1;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_remainder(char *buffer)
{
	char	*remainder;
	size_t	i;
	size_t	j;

	i = 0;
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!remainder)
		return (NULL);
	j = 0;
	while (buffer[i])
		remainder[j++] = buffer[++i];
	remainder[j] = '\0';
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_get_actual_line(buffer);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	buffer = ft_remainder(buffer);
	return (line);
}
