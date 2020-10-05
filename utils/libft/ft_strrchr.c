/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:33:47 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/11 19:46:20 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int len;

	len = ft_strlen(str);
	str += len - 1;
	if ((char)ch == '\0')
		return ((char *)str + 1);
	while (len--)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
