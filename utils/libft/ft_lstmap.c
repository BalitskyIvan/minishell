/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <lmallado@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 00:13:51 by lmallado          #+#    #+#             */
/*   Updated: 2020/05/23 01:04:23 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*res;

	newl = ft_lstnew((*f)(lst->content));
	res = newl;
	if (newl == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next)
		{
			newl->next = ft_lstnew((*f)(lst->next->content));
			if (newl->next == NULL)
			{
				ft_lstclear(&res, (*del));
				return (0);
			}
			newl = newl->next;
		}
		lst = lst->next;
	}
	newl->next = NULL;
	return (res);
}
