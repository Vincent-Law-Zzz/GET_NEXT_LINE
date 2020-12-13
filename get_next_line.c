/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:26:30 by aapollo           #+#    #+#             */
/*   Updated: 2020/12/13 20:08:50 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*reminder;
	int			flag;

	if (!(reminder = malloc(BUFFER_SIZE + 1)))
		return (0);
	reminder[0] = '\0';
	flag = 1;
	while ((flag > 0) && (reminder != '\0'))
	{
		flag = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		reminder = ft_strjoin(reminder, buff);
		while (*reminder != '\0')
			reminder++;
	}
	printf("%s\n", reminder);
	*line = ft_strdup(reminder);
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
