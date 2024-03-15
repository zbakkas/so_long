/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:52 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/24 15:46:45 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*re;
	int		x;

	x = 0;
	if (!s || !f)
		return (NULL);
	re = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!re)
		return (NULL);
	while (s[x])
	{
		re[x] = f(x, s[x]);
		x++;
	}
	return (re);
}
