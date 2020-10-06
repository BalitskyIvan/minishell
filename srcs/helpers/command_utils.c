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

#include "../../includes/minishell.h"

t_command	*_create(char *command_string, char **args, int option)
{
	t_command	*command;

	command = init_command_basic();
	command->args = args;
	command->command_str = command_string;
	command->option = option;
	return (command);
}
