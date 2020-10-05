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

void	*ft_memccpy(void *source_1, const void *source_2, int c, size_t count)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char*)source_1;
	s2 = (unsigned char*)source_2;
	i = 0;
	if (!source_1 && !source_2)
		return (source_1);
	while (i < count)
	{
		*s1 = s2[i];
		s1++;
		if (s2[i] == (unsigned char)c)
			return (s1);
		i++;
	}
	return (NULL);
}
