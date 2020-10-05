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

void	*ft_memcpy(void *source_1, const void *source_2, size_t count)
{
	unsigned char		*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (unsigned char*)source_1;
	s2 = (unsigned char*)source_2;
	i = 0;
	if (!source_1 && !source_2)
		return (source_1);
	while (i < count)
	{
		s1[i] = s2[i];
		i++;
	}
	return (source_1);
}
