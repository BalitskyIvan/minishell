/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:11:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/13 13:42:54 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		check_redirect(t_command *command)
{
	int	res;

	res = 1;
	if (command->command_str != NULL)
		res = get_file(command->command_str, command->redirect_type);
	if (command->redirect != NULL)
	{
		if (command->redirect->command_str != NULL)
			return (check_redirect(command->redirect));
	}
	return ((res == -1) ? 0 : res);
}
