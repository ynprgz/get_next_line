/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:27:06 by yaperalt          #+#    #+#             */
/*   Updated: 2024/11/23 15:38:15 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;

	fd = open("hola.txt", O_RDONLY);
	fd2 = open("hola2.txt", O_RDONLY);
	fd3 = open("hola3.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line: %s", line);
	line = get_next_line(fd2);
	printf("line: %s", line);
	line = get_next_line(fd3);
	printf("line: %s", line);
	line = get_next_line(fd);
	printf("line: %s", line);
	line = get_next_line(fd2);
	printf("line: %s", line);
	line = get_next_line(fd3);
	printf("line: %s", line);
	return (0);
}
