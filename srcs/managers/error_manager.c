/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:13:44 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 20:39:35 by mklotz           ###   ########.fr       */
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
	printf("%s %s\n", SYNTAX_ERROR, str);
}
