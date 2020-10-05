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

void	*ft_memchr(const void *buffer, int ch, size_t count)
{
	unsigned const char	*s1;
	size_t				i;

	s1 = (unsigned char*)buffer;
	i = 0;
	while (i < count)
	{
		if (s1[i] == (unsigned char)ch)
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
