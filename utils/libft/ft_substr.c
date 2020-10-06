/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:03:35 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/22 18:14:54 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i[2];
	size_t			s_len;

	i[0] = -1;
	i[1] = 0;
	if (s && ((s_len = ft_strlen(s)) < start || len == 0))
		return (ft_strdup(""));
	if (s && len > s_len - start)
		len = s_len - start;
	if (!s || !(substr = (char *)malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (s[++i[0]] && len != 0)
		if (i[0] >= start && i[1] < len)
			substr[i[1]++] = s[i[0]];
	substr[i[1]] = '\0';
	return (substr);
}
