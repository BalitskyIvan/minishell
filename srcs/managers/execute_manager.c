/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:32:33 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/20 11:58:50 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		hook_my_functions(t_main *main, t_command *command)
{
	if (ft_strncmp(command->args[0], "exit", -1) != 0)
		main->status = 0;
	if (ft_strncmp(command->args[0], "pwd", -1) == 0)
		return (ft_pwd(main, command));
	else if (ft_strncmp(command->args[0], "env", -1) == 0)
		return (ft_env(main));
	else if (ft_strncmp(command->args[0], "cd", -1) == 0)
		return (change_directory(command, main));
	else if (ft_strncmp(command->args[0], "echo", -1) == 0)
		return (ft_echo(command, main));
	else if (ft_strncmp(command->args[0], "exit", -1) == 0)
		return (ft_exit(command, main));
	else if (ft_strncmp(command->args[0], "unset", -1) == 0)
		return (env_manager(main, command, 1));
	else if (ft_strncmp(command->args[0], "export", -1) == 0)
		return (env_manager(main, command, 0));
	return (0);
}

int		execute_another_function(t_main *main, t_command *command)
{
	pid_t	pid;
	int		status;
	int		pfd[2];

	get_pipe_main(main, command, pfd);
	pid = fork();
	if (pid == 0)
	{
		get_pipe_support(main, command, pfd);
		check_redirect(command->redirect);
		status = execve(command->command_str,
		command->args, main->env);
		if (status == -1)
			send_custom_error("Command not found!");
		exit(0);
	}
	else if (pid < 0)
		send_error();
	else
	{
		wait(&pid);
		main->status = WEXITSTATUS(pid);
		check_pipe(main, command, pfd);
	}
	return (0);
}

void	execute(t_main *main)
{
	char	*temp;

	errno = 0;
	if (main->command == NULL)
		send_custom_error("Command not found!");
	while (main->command != NULL)
	{
		if (main->command->command_str != NULL)
		{
			if (hook_my_functions(main, main->command) == 0)
			{
				temp = main->command->command_str;
				main->command->command_str = get_command_path(main,
				main->command->command_str);
				free(temp);
				if (main->command->command_str == NULL)
				{
					main->status = 127;
					send_custom_error("Command not found!");
				}
				else
					execute_another_function(main, main->command);
			}
		}
		else
			send_custom_error("Command not found!");
		main->command = main->command->next;
	}
}
