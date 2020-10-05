/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 21:15:47 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/16 16:35:11 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_malloc(char *str)
{
	char	*result;
	int		i;

	i = -1;
	result = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (str[++i])
		result[i] = str[i];
	result[i] = '\0';
	return (result);
}

static int	get_number_long(int n)
{
	int		result;

	result = 0;
	while (n != 0)
	{
		result++;
		n = n / 10;
	}
	return ((result == 0) ? 1 : result);
}

char		*ft_itoa(int n)
{
	int		plus;
	int		number_long;
	char	*number;

	if (n == 0)
		return (str_malloc("0"));
	if (n == -2147483648)
		return (str_malloc("-2147483648"));
	plus = (n < 0) ? 2 : 1;
	number_long = get_number_long(n);
	number = (char *)malloc(number_long * sizeof(char) + plus);
	if (!number)
		return (NULL);
	number[number_long + plus - 1] = '\0';
	if (plus == 2)
		n = n * -1;
	while (n != 0)
	{
		number[(plus == 2) ? number_long-- : --number_long] = (n % 10) + '0';
		n = n / 10;
	}
	if (plus == 2)
		number[0] = '-';
	return (number);
}
