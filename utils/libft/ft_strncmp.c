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

int	ft_strncmp(const char *buf1, const char *buf2, size_t count)
{
	unsigned char	*buf1c;
	unsigned char	*buf2c;
	size_t			i;

	i = 0;
	buf1c = (unsigned char*)buf1;
	buf2c = (unsigned char*)buf2;
	if (count != 0)
	{
		while (buf1c[i] == buf2c[i] &&
			i < count - 1 &&
			buf1c[i] != '\0' && buf2c[i] != '\0')
			i++;
	}
	else
		return (0);
	return (buf1c[i] - buf2c[i]);
}
