/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:09:43 by mklotz            #+#    #+#             */
/*   Updated: 2020/05/16 16:39:37 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int ch)
{
	return (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ? ch : 0);
}
