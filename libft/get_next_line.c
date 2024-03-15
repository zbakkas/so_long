/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:55 by zbakkas           #+#    #+#             */
/*   Updated: 2024/03/12 20:25:34 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	    char		*buff;
	int			x=1;
	char	*str =NULL;
    buff = malloc(1+4);
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
    return str;
}
