/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:37:01 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/22 18:11:45 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	if ((temp = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	result = temp;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if ((temp = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&result, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&result, temp);
	}
	return (result);
}
