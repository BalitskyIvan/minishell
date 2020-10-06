/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:05:42 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 20:42:14 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command	*init_command_basic(void)
{
	t_command	*command;

	if ((command = (t_command *)malloc(sizeof(t_command))) == NULL)
		send_error();
	command->args = NULL;
	command->command_str = NULL;
	command->is_pipe = 0;
	command->next = NULL;
	command->prev = NULL;
	return (command);
}

t_main	global_init(char *argv[], char *env[])
{
	t_main	main;

	main.argv = argv;
	main.env = env;
	main.command = init_command_basic();
	send_invitation();
	return (main);
}
