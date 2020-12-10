/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:26:30 by aapollo           #+#    #+#             */
/*   Updated: 2020/12/10 21:14:57 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buff[BUFFER_SIZE];

	read(fd, buff, BUFFER_SIZE);
	write(1, buff, 64);
	return (0);
}

int	main(void)
{
	int		fd;
	char	**line;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, line);
	printf("%d\n", fd);
	return (0);
}
