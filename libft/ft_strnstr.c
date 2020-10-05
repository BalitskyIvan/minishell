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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i2;
	int		i3;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		i2 = i;
		i3 = 0;
		while (big[i2] == little[i3] && i2 < len)
		{
			i3++;
			if (little[i3] == '\0')
				return ((char *)big + i);
			i2++;
		}
		i++;
	}
	return (NULL);
}
