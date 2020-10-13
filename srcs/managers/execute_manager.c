/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:32:33 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/13 14:42:13 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		hook_my_functions(t_main *main, t_command *command)
{
	if (ft_strncmp(command->args[0], "pwd", -1) == 0)
	{
		printf("%s\n", get_env_value(main, "PWD"));
		return (1);
	} 
	else if (ft_strncmp(command->args[0], "env", -1) == 0)
		return(ft_env(main));
	else if (ft_strncmp(command->args[0], "cd", -1) == 0)
		return(ft_cd(command));
	else if (ft_strncmp(command->args[0], "exit", -1) == 0)
		ft_exit(command);
	return (0);
}

int		execute_another_function(t_main *main, t_command *command)
{
	pid_t	pid;
	int		status;
	int		fd;

	pid = fork();
	if (pid == 0)
	{
		status = check_redirect(command, &fd);
		dup2(fd, (status == 3) ? 0 : 1);
		status = execve(command->command_str,
		command->args, main->env);
		close(fd);
		if (status == -1)
			send_custom_error("Command not found!");
	}
	else if (pid < 0)
		send_error();
	else
		wait(&pid);
	return (0);
}

void	execute(t_main *main)
{
	errno = 0;
	if (main->command == NULL)
		send_custom_error("Command not found!");
	while (main->command != NULL)
	{
		if (main->command->command_str != NULL)
		{
			if (hook_my_functions(main, main->command) == 0)
			{
				main->command->command_str = get_command_path(main, main->command->command_str);
				if (main->command->command_str == NULL)
					send_custom_error("Command not found!");
				else
					execute_another_function(main, main->command);
			}
		}
		else
			send_custom_error("Command not found!");
		main->command = main->command->next;
	}
}
