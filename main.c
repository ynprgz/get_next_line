/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 00:55:34 by yaperalt          #+#    #+#             */
/*   Updated: 2024/11/23 15:30:01 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("hola.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line: %s", line);
	line = get_next_line(fd);
	printf("line: %s", line);
	line = get_next_line(fd);
	printf("line: %s", line);
	line = get_next_line(fd);
	printf("line: %s", line);
	line = get_next_line(fd);
	printf("line: %s", line);
	line = get_next_line(fd);
	printf("line: %s", line);
	return (0);
}
