/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:05:57 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/26 15:37:16 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nexttte;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nexttte = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nexttte;
	}
	*lst = NULL;
}
