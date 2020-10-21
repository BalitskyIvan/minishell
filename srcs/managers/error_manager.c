/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:13:44 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/21 13:39:49 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	send_error(void)
{
	if (errno != 0)
	{
		perror(ERROR);
		exit(errno);
	}
}

void	send_custom_error(char *str)
{
	ft_putstr_fd(SYNTAX_ERROR, 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}
