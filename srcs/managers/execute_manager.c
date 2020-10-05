/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:32:33 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/06 00:10:47 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		hook_my_functions(t_main *main, char *command)
{
	int		i;

	i = -1;
	if (ft_strncmp(command, "pwd", -1) == 0)
	{
		printf("%s\n", get_env_value(main, "PWD"));
		return (1);
	} 
	else if (ft_strncmp(command, "env", -1) == 0)
	{
		while (main->env[++i])
			printf("%s\n", main->env[++i]);
		return (1);
	}
	else if (ft_strncmp(command, "cd", -1) == 0)
	{
		chdir("/");
	}
	return (0);
}

int		execute_another_function(t_main *main)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		status = execve(main->com->command, main->com->args, main->env);
		if (status == -1)
			send_custom_error("Command not found!");
	}
	else if (pid < 0)
		send_error();
	else
		wait(&pid);
	return (0);
}

void	execute_managers(t_main *main, char *cmd)
{
	char	*patch;

	if (hook_my_functions(main, cmd) == 0)
	{
		main->com->args = ft_split(cmd, ' ');
		patch = get_command_patch(main, main->com->args[0]);
		main->com->command = patch;
		execute_another_function(main);
	}
}
