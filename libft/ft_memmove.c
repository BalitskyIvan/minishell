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

void	*ft_memmove(void *to, const void *from, size_t count)
{
	char		*s1;
	const char	*s2;
	int			i;

	s1 = to;
	s2 = from;
	i = count - 1;
	if (!to && !from)
		return (NULL);
	if (s1 < s2)
		return (ft_memcpy(s1, s2, count));
	while (i >= 0)
	{
		s1[i] = s2[i];
		i--;
	}
	return (s1);
}
