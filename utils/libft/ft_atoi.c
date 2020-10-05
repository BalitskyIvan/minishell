/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:20:13 by mklotz            #+#    #+#             */
/*   Updated: 2020/08/23 12:47:54 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_long_max(const char *str, int i, int sign)
{
	int num_size;

	num_size = 0;
	while (str[i] && ft_isdigit((char)str[i]))
	{
		if (str[i] == '0' && num_size == 0)
		{
			i++;
			continue ;
		}
		num_size++;
		i++;
	}
	if (num_size > 19)
		return ((sign == -1) ? 0 : -1);
	return (777);
}

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;
	int					checker;
	int					temp;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' ||
	str[i] == '\r' || str[i] == '\n' || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	temp = i;
	checker = check_long_max(str, i, sign);
	if (checker != 777)
		return (checker);
	while (str[i] && ft_isdigit((char)str[i]))
	{
		res = res * 10 + ((int)str[i++] - 48);
		if (res > 9223372036854775807)
			return ((sign > 0) ? -1 : 0);
	}
	return ((ft_isdigit((char)str[temp]) > 0) ? res * sign : -1);
}
