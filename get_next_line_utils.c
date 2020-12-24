/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapollo <aapollo@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:27:42 by aapollo           #+#    #+#             */
/*   Updated: 2020/12/22 22:04:20 by aapollo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		counter;

	counter = 0;
	if (!s1)
		return (NULL);
	if (!(p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)
		+ 1) * sizeof(char))))
		return (NULL);
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		if (*s1 != '\0')
		{
			p[counter] = *s1;
			s1++;
		}
		else
		{
			p[counter] = *s2;
			s2++;
		}
		counter++;
	}
	p[counter] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		counter;

	res = NULL;
	if (!s1 || !(*s1)
	|| !(res = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	counter = 0;
	while (*s1 != '\0')
	{
		res[counter] = *s1;
		s1++;
		counter++;
	}
	res[counter] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}
