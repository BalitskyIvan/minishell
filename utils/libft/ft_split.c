/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:26:02 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/22 18:54:58 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt(char const *s, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i++] == c)
			res++;
	}
	return (res + 1);
}

static int	leight(const char *s, char c, int i)
{
	int res;

	res = 0;
	while (s[i])
	{
		if (s[i++] != c)
			res++;
		else
			break ;
	}
	return (res);
}

static char	**arr_free(char const **arr, int i)
{
	while (i + 1)
		free((void *)arr[i--]);
	free(arr);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	if (!s || (!c && c != '\0'))
		return (NULL);
	if (!(arr = (char **)malloc((cnt(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (s[i[0]])
	{
		if (s[i[0]] != c && s[i[0]] != '\0')
		{
			i[2] = 0;
			arr[i[1]] = (char *)malloc(leight(s, c, i[0]) * sizeof(char) + 1);
			if (arr[i[1]] == NULL)
				return (arr_free((char const**)arr, i[1]));
			while (s[i[0]] != c && s[i[0]] != '\0')
				arr[i[1]][i[2]++] = s[i[0]++];
			arr[i[1]++][i[2]] = '\0';
		}
		i[0] += (s[i[0]] != '\0') ? 1 : 0;
	}
	arr[i[1]] = NULL;
	return (arr);
}
