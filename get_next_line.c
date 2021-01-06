/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:26:30 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/06 12:56:50 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_get_line(char **line, char **reminder, char *endofstr)
{
	char	*tmp;

	tmp = *reminder;
	*endofstr = '\0';
	if (!(*line = ft_strdup(*reminder)))
		return (-1);
	if (!(*reminder = ft_strdup((endofstr + 1))))
		return (-1);
	free(tmp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*reminder;
	int			flag;
	char		*endofstr;

	flag = 1;
	endofstr = NULL;
	if ((reminder != NULL) && (endofstr = ft_strchr(reminder, '\n')))
		flag = ft_get_line(line, &reminder, endofstr);
	while (!(endofstr) && (flag != -1) && (flag = read(fd, buff, BUFFER_SIZE)))
	{
		buff[BUFFER_SIZE] = '\0';
		if (!(reminder = (reminder == NULL) ? ft_strdup(buff) :
			ft_strjoin(reminder, buff)))
			return (-1);
		if ((endofstr = ft_strchr(reminder, '\n')))
			flag = ft_get_line(line, &reminder, endofstr);
	}
	if (flag == 0)
		if (!(*line = ft_strdup("\0")))
			return (-1);
	if (flag <= 0)
		return (flag);
	return (1);
}

int		main(void)
{
	unsigned	int	fd = 0;
	char	*line;
	int		ret = 0;
	int		counter = 0;

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		printf("|%d|\n", ret);
		free(line);
		counter++;
		getchar();
	}
	counter++;
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("|%d|\n", ret);
	printf("|%d strcount|\n", counter);
		free(line);
		getchar();
	return (0);
}
