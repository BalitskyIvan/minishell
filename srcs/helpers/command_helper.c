/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:18:12 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/06 16:43:51 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command	*get_first_command(t_command *command)
{
	while (command->prev != NULL)
		command = command->prev;
	return (command);
}

t_command	*get_last_command(t_command *command)
{
	while (command->next != NULL)
		command = command->next;
	return (command);
}

t_command	*get_command(t_main *main, int element)
{
	t_command	*command;

	command = get_first_command(main->command);
	while (element != 0 && command->next != NULL)
	{
		command = command->next;
		element--;
	}
	return ((element != 0) ? NULL : command);
}

void	command_add_front(t_command *command, t_main *main)
{
	t_command	*first;

	first = get_first_command(main->command);
	command->next = first;
	command = first;
}

void	command_add_back(t_command *command, t_main *main)
{
	t_command	*last;

	last = get_last_command(main->command);
	last->next = command;
	command->prev = last;
}
