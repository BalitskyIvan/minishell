/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:22:11 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/08 18:24:20 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int ch)
{
	return (ch > 31 && ch < 127) ? ch : 0;
}
