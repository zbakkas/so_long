/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:55 by zbakkas           #+#    #+#             */
/*   Updated: 2024/04/30 21:43:16 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

static void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, size * count);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		xx;
	int		x;

	x = 0;
	xx = 0;
	if (!s1 || !s2)
		return (0);
	re = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!re)
		return (NULL);
	while (s1[x])
	{
		re[xx] = s1[x];
		x++;
		xx++;
	}
	x = 0;
	while (s2[x])
	{
		re[xx] = s2[x];
		xx++;
		x++;
	}
	return (free(s1), re);
}

char	*get_next_line(int fd)
{
	char		*buff;
	int			x;
	char		*str;

	str = NULL;
	buff = malloc(1 + 4);
	x = 1;
	str = malloc(1);
	str[0] = '\0';
	while (x > 0)
	{
		x = read(fd, buff, 4);
		if (x < 0)
			return (free(buff), NULL);
		buff[x] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
