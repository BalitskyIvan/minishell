/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coma_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:18:12 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 20:37:22 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_coma	*coma_get_first(t_coma *coma)
{
	while (coma->prev != NULL)
		coma = coma->prev;
	return (coma);
}

t_coma	*coma_get_last(t_coma *coma)
{
	while (coma->next != NULL)
		coma = coma->next;
	return (coma);
}

t_coma	*coma_get_element(t_main *main, int elem)
{
	t_coma	*coma;

	coma = coma_get_first(main->com);
	while (elem != 0 && coma->next != NULL)
	{
		coma = coma->next;
		elem--;
	}
	return ((elem != 0) ? NULL : coma);
}

void	coma_add_front(t_coma *coma, t_main *main)
{
	t_coma	*first;

	first = coma_get_first(main->com);
	coma->next = first;
	coma = first;
}

void	coma_add_back(t_coma *coma, t_main *main)
{
	t_coma	*last;

	last = coma_get_last(main->com);
	last->next = coma;
	coma->prev = last;
}
