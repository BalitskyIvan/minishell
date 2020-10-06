/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:32:33 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/06 03:42:32 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		hook_my_functions(t_main *main)
{
	if (ft_strncmp(main->command->args[0], "pwd", -1) == 0)
	{
		printf("%s\n", get_env_value(main, "PWD"));
		return (1);
	} 
	else if (ft_strncmp(main->command->args[0], "env", -1) == 0)
		return(ft_env(main));
	else if (ft_strncmp(main->command->args[0], "cd", -1) == 0)
		return(ft_cd(main));
	else if (ft_strncmp(main->command->args[0], "exit", -1) == 0)
		ft_exit(main);
	return (0);
}

int		execute_another_function(t_main *main)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		status = execve(main->command->command_str,
		main->command->args, main->env);
		if (status == -1)
			send_custom_error("Command not found!");
	}
	else if (pid < 0)
		send_error();
	else
		wait(&pid);
	return (0);
}

void	execute(t_main *main, char *cmd)
{
	char	*path;

	main->command->args = ft_split(cmd, ' ');
	path = get_command_path(main, main->command->args[0]);
	if (hook_my_functions(main) == 0)
	{
		main->command->command_str = path;
		execute_another_function(main);
	}
}
