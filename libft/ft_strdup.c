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

void	*ft_strdup(const char *source)
{
	int		i;
	char	*s;

	i = 0;
	while (source[i] != '\0')
		i++;
	s = malloc(i + 1);
	if (s)
	{
		i = 0;
		while (source[i] != '\0')
		{
			s[i] = source[i];
			i++;
		}
		s[i] = '\0';
	}
	return (s);
}
