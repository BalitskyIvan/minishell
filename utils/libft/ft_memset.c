/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:35:17 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/16 14:05:13 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)destination;
	while (n > 0)
	{
		*(temp) = (unsigned char)c;
		if (n--)
			temp++;
	}
	return (destination);
}
