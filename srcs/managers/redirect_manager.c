/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:11:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/13 12:38:22 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		check_redirect(t_command *command)
{
	int	res;

	res = 0;
	if (command->redirect != NULL || command->double_redirect != NULL)
	{
		if (command->redirect != NULL && command->redirect->command_str != NULL)
			return (check_redirect(command->redirect));
		else if (command->double_redirect->command_str != NULL)
			return (check_redirect(command->double_redirect));
	}
	else if (command->command_str != NULL)
		res = get_file(command->command_str, '0');
	return ((res == -1) ? 0 : res);
}
