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

static int		skip_set_front(char const *s1, char const *set, int end)
{
	int	is1;
	int	iset;
	int	count_to_skip;

	is1 = 0;
	iset = 0;
	count_to_skip = 0;
	while (set[iset] != '\0' && is1 < end)
	{
		if (set[iset] == s1[is1])
		{
			count_to_skip++;
			iset = 0;
			is1++;
		}
		else
			iset++;
	}
	return (count_to_skip);
}

static int		skip_set_back(char const *s1, char const *set,
								int start, int end)
{
	int	is1;
	int	iset;
	int	count_to_skip;

	is1 = end - 1;
	iset = 0;
	count_to_skip = 0;
	while (set[iset] != '\0' && end > start)
	{
		if (set[iset] == s1[is1])
		{
			count_to_skip++;
			iset = 0;
			is1--;
		}
		else
			iset++;
	}
	return (count_to_skip);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		newstart;
	int		newend;
	int		i;

	i = 0;
	newend = ft_strlen(s1);
	newstart = skip_set_front(s1, set, newend);
	if (newstart < newend)
		newend -= skip_set_back(s1, set, newstart, newend);
	res = (char *)malloc((newend - newstart + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (newstart < newend)
	{
		res[i] = s1[newstart];
		newstart++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
