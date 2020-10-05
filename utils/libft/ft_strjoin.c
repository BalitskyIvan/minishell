/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:00:06 by mklotz            #+#    #+#             */
/*   Updated: 2020/08/23 10:03:06 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len[2];
	int		i[2];
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return ((s1) ? ft_strdup(s1) : ft_strdup(s2));
	len[0] = ft_strlen((char *)s1);
	len[1] = ft_strlen((char *)s2);
	if (!(str = (char *)malloc((len[0] + len[1]) * sizeof(char) + 1)))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (len[0] > 0 || len[1] > 0)
	{
		if (len[0]-- > 0)
			str[i[0]] = s1[i[0]];
		else if (len[1]-- > 0)
			str[i[0]] = s2[i[1]++];
		i[0]++;
	}
	str[i[0]] = '\0';
	return (str);
}
