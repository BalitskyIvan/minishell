/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:11:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/19 19:30:39 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		check_redirect(t_command *command)
{
	int		res;
	int		fd;

	res = -1;
	if (command != NULL && command->command_str != NULL)
	{
		fd = get_file(command->command_str, command->redirect_type);
		res = command->redirect_type;
		dup2(fd, (res == 3) ? 0 : 1);
		check_redirect(command->redirect);
	}
	return (res);
}

int		get_pipe_main(t_main *main, t_command *command, int pfd[2])
{
    (void)main;
	if (command != NULL && command->command_str != NULL)
	{
		if (command->pipe != NULL && command->pipe->command_str != NULL)
			pipe(pfd);
	}
	return (0);
}

int		get_pipe_support(t_main *main, t_command *command, int pfd[2])
{
    (void)main;
	if (command != NULL && command->command_str != NULL)
	{
		if (command->pipe != NULL && command->pipe->command_str != NULL)
		{
			close(pfd[0]);
			dup2(pfd[1], 1);
		}
	}
	return (0);
}

int		check_pipe(t_main *main, t_command *command, int pfd[2])
{
	char	*temp;

	if (command != NULL && command->command_str != NULL)
	{
		if (command->pipe != NULL && command->pipe->command_str != NULL)
		{
			close(pfd[1]);
			dup2(pfd[0], 0);
			temp = command->pipe->command_str;
			command->pipe->command_str =
			get_command_path(main, command->pipe->command_str);
			free(temp);
			execute_another_function(main, command->pipe);
			dup2(main->main_0, 0);
		}
	}
	return (0);
}
