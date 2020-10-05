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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		res[i] = s2[i2];
		i++;
		i2++;
	}
	res[i] = '\0';
	return (res);
}
