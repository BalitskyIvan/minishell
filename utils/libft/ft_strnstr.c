/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:57:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/14 22:08:13 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i[2];

	i[0] = -1;
	if (!*little)
		return ((char *)big);
	while (big[++i[0]] && (size_t)i[0] < len)
		if (big[i[0]] == little[0])
		{
			i[1] = 0;
			while (big[i[0] + i[1]] == little[i[1]] && little[i[1]]
			&& (size_t)(i[0] + i[1]) <= len)
				i[1]++;
			if (!little[i[1]])
				return ((char *)&big[i[0]]);
		}
	return (NULL);
}
