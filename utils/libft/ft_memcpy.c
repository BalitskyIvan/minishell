/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:50:06 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/11 18:28:01 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	if (!n || destination == source)
		return (destination);
	str1 = (unsigned char *)destination;
	str2 = (unsigned char *)source;
	while (n--)
		*(str1++) = *(str2++);
	return (destination);
}
