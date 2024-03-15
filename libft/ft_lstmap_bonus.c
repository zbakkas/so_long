/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:47:34 by zbakkas           #+#    #+#             */
/*   Updated: 2023/12/26 15:46:19 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elm;
	void	*v;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		v = f(lst->content);
		elm = ft_lstnew(v);
		if (!elm)
		{
			del(v);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, elm);
		lst = lst->next;
	}
	return (new);
}
