/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:31:43 by mklotz            #+#    #+#             */
/*   Updated: 2020/09/27 18:40:25 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	ft_list_sort(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (lst.s < lst->next.s)
			list_swap(&list);		
	}
}

void list_swap(t_list *list)
{
	int temp_s;

	temp_s = list->next.s;
	list->next.s = list.s;
	list.s = list->next.s;
}
