/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:26:30 by aapollo           #+#    #+#             */
/*   Updated: 2021/01/13 18:31:27 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_get_line(char **line, char **remainder, char *endofstr, int flag)
{
	char	*tmp;

	if (!(*remainder))
		return(-1);
	if (flag > 0)
	{
		tmp = *remainder;
		*endofstr = '\0';
		if (!(*line = ft_strdup(*remainder)))
			return (-1);
		if (!(*remainder = ft_strdup((endofstr + 1))))
			return (-1);
		free(tmp);
		return (1);
	}
	if (flag == 0)
	{
		if (!(*line = ft_strdup(*remainder)))
			return (-1);
		return (0);
	}
	if (flag < 0)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*remainder;
	int			flag;
	char		*endofstr;

	if (!line || (fd < 0) || (BUFFER_SIZE <= 0))
		return (-1);
	flag = 1;
	endofstr = NULL;
	if ((remainder != NULL) && (endofstr = ft_strchr(remainder, '\n')))
		return (ft_get_line(line, &remainder, endofstr, flag));
	while ((endofstr == NULL) && (flag = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (flag > 0)
			buff[flag] = '\0';
		if (buff[0] == '\0')
			return (0);
		if (!(remainder = (remainder == NULL) ? ft_strdup(buff) :
			ft_strjoin(remainder, buff)))
			return (-1);
		if ((endofstr = ft_strchr(remainder, '\n')))
			return (ft_get_line(line, &remainder, endofstr, flag));
	}
	return (ft_get_line(line, &remainder, endofstr, flag));
}

int		main(void)
{
    int	fd = 0;
    char	*line;
    int		ret = 0;
    int		counter = 0;

    fd = open("gnl-war-machine-v2019/tests/63_line", 0x000);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        printf("|%d|\n", ret);
        free(line);
        counter++;
        //getchar();
    }
    counter++;
	// free(line);
    printf("%s\n", line);
	// free(line);
    printf("|%d|\n", ret);
    printf("|%d strcount|\n", counter);
    //getchar();
    return (0);
}
