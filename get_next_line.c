/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:26:30 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/05 21:01:20 by aapollo          ###   ########.fr       */
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
	return (0);
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
		ft_get_line(line, &reminder, endofstr);
	while (!(endofstr) && (flag = read(fd, buff, BUFFER_SIZE)))
	{
		buff[BUFFER_SIZE] = '\0';
		if (!(reminder = (reminder == NULL) ? ft_strdup(buff) :
			ft_strjoin(reminder, buff)))
			return (-1);
		if ((endofstr = ft_strchr(reminder, '\n')))
			ft_get_line(line, &reminder, endofstr);
	}
	if (flag == 0)
		if (!(*line = ft_strdup(reminder)))
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

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		printf("|%d|\n", ret);
		free(line);
		//getchar();
	}
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("|%d|\n", ret);
		free(line);
		//getchar();
	return (0);
}
