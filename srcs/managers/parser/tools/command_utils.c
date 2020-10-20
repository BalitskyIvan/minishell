/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:32:00 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/20 13:12:00 by mklotz           ###   ########.fr       */
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
	command->redirect_type = -1;
	command->endpoint_type = -1;
	command->redirect = NULL;
	command->next = NULL;
	command->prev = NULL;
	return (command);
}

t_command	*create_obj(char *command_string, char **args)
{
	t_command	*command;

	command = init_command_basic();
	if (command_string == NULL || args == NULL)
	{
        command->args = args;
        command->command_str = command_string;
        command->undefined_arg = 1;
    }
	else
	{
		command->args = args;
		command->command_str = command_string;
	}
	return (command);
}

void		join_str(char **dst, char *c)
{
	char	*temp;

	temp = *dst;
	*dst = ft_strjoin(*dst, c);
	free(c);
	free(temp);
}
