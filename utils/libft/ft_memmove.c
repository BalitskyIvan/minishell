/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:04:31 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/16 16:14:29 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	if (!n || destination == source)
		return (destination);
	i = 0;
	str1 = (unsigned char *)destination;
	str2 = (unsigned char *)source;
	if (str2 > str1)
		while (n--)
			*(str1++) = *(str2++);
	else
		while ((size_t)++i <= n)
			str1[n - i] = str2[n - i];
	return (destination);
}
