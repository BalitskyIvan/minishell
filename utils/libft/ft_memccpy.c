/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:55:48 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/11 18:50:39 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = -1;
	str1 = (unsigned char *)destination;
	str2 = (unsigned char *)source;
	while ((size_t)++i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return (str1 + i + 1);
	}
	return (NULL);
}
