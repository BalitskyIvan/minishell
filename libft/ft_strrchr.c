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

char	*ft_strrchr(const char *str, int ch)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)str;
	while (res[i] != '\0')
		i++;
	while (i > 0)
	{
		if (res[i] == ch)
			return (res + i);
		i--;
	}
	if (res[i] == ch)
		return (res + i);
	return (NULL);
}
