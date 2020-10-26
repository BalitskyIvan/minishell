/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_custom_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:06:49 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/24 15:10:58 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int		ft_exit_errors(t_command *command)
{
	int		i;
	int		status;

	i = -1;
	status = -1;
	if (command->args[1] != NULL)
	{
		while (command->args[1][++i])
			if (ft_isalpha(command->args[1][++i]) != 0)
				status = 255;
		if (status != 255 && get_sizeof_args(command->args) > 2)
			status = 1;
	}
	if (command->pipe == NULL)
		ft_putstr_fd("exit\n", 1);
	if (status != -1)
		send_custom_error((status == 255) ? "Numeric argument required"
										: "Too many arguments");
	return (status);
}

int		ft_exit(t_command *command, t_main *main)
{
	int		error;
	char	*temp;

	check_redirect(command);
	dup2(main->main_1, 1);
	error = ft_exit_errors(command);
	error = (error == -1) ? main->status : error;
	if (command->args[1] != NULL)
		error = (error == -1 || error == main->status) ?
								ft_atoi(command->args[1]) : error;
	if (command->pipe == NULL && error != 1)
		exit(error);
	else if (command->pipe != NULL)
	{
		main->status = 0;
		temp = command->pipe->command_str;
		command->pipe->command_str = get_command_path(main,
									command->pipe->command_str);
		free(temp);
		execute_another_function(main, command->pipe);
	}
	else
		main->status = (error == 1) ? error : main->status;
	return (1);
}

int		ft_env(t_main *main, t_command *command)
{
	int		i;

	i = -1;
	ft_get_pipe(main, command->pipe, 0);
	check_redirect(command);
	while (main->env[++i])
	{
		if (ft_strrchr(main->env[i], '=') != 0)
		{
			ft_putstr_fd(main->env[i], 1);
			ft_putstr_fd("\n", 1);
		}
	}
	ft_get_pipe(main, command->pipe, 1);
	return (1);
}

void	ft_get_pipe(t_main *main, t_command *command, int type)
{
	static int		pfd[2];
	char			*temp;

	if (command != NULL)
	{
		if (type == 0)
		{
			pipe(pfd);
			dup2(pfd[1], 1);
		}
		else if (close(pfd[1]) || 1 == 1)
		{
			dup2(main->main_1, 1);
			dup2(pfd[0], 0);
			if (hook_my_functions(main, command) == 0)
			{
				temp = command->command_str;
				command->command_str = get_command_path(main,
										command->command_str);
				execute_another_function(main, command);
				free(temp);
			}
			dup2(main->main_0, 0);
		}
	}
}

int		ft_echo(t_command *command, t_main *main)
{
	int		i;
	int		stop;

	i = 0;
	ft_get_pipe(main, command->pipe, 0);
	check_redirect(command);
	if ((stop = 0) || command->args[1] == NULL)
	{
		ft_putchar_fd('\n', 1);
		return (1);
	}
	while (command->args[++i])
	{
		if (stop == 0 && ft_strncmp(command->args[i], "-n", -1) == 0)
			continue ;
		ft_putstr_fd(command->args[i], 1);
		stop = 1;
		if (command->args[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
	}
	if (ft_strncmp(command->args[1], "-n", -1) != 0)
		ft_putchar_fd('\n', 1);
	ft_get_pipe(main, command->pipe, 1);
	return (1);
}
