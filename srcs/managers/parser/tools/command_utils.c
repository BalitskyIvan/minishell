/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:32:00 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/06 16:39:34 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

t_command	*init_command_basic(void)
{
	t_command	*command;

	if ((command = (t_command *)malloc(sizeof(t_command))) == NULL)
		send_error();
	command->args = NULL;
	command->command_str = NULL;
	command->pipe = NULL;
	command->undefined_arg = 0;
	command->redirect = NULL;
	command->back_redirect = NULL;
	command->double_redirect = NULL;
	command->next = NULL;
	command->prev = NULL;
	return (command);
}

t_command	*_create(char *command_string, char **args)
{
	t_command	*command;

	command = init_command_basic();
	if (command_string == NULL || args == NULL)
		command->undefined_arg = 1;
	else
	{
		command->args = args;
		command->command_str = command_string;
	}
	return (command);
}