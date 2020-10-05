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

static int		wsize(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] && (char)s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static int		getwordscount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((char)s[i] != c && s[i])
		{
			count++;
			while ((char)s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

void			free_mem(char **res, int i)
{
	while (i > 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
}

int				write_word(char *res, const char *s, char c, int i)
{
	int	ys;

	ys = 0;
	while ((char)s[i] != c && s[i] != '\0')
		res[ys++] = s[i++];
	res[ys] = '\0';
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		xs;

	xs = 0;
	i = 0;
	if (!(res = (char **)malloc((getwordscount(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (s[i] != '\0')
	{
		while ((char)s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!(res[xs] = (char *)malloc((wsize(s, c, i) + 1))))
			{
				free_mem(res, i);
				return (NULL);
			}
			i = write_word(res[xs++], s, c, i);
		}
	}
	res[xs] = 0;
	return (res);
}
