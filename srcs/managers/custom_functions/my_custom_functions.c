/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_custom_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:06:49 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/21 16:32:43 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exit_support(char *arg, t_command *command, t_main *main)
{
	int		i;

	i = -1;
	while (arg[++i])
	{
		if (ft_isalpha(arg[i]) > 0)
		{
			ft_putstr_fd("exit\n", 1);
			send_custom_error("Numeric argument required!");
			if (command->pipe == NULL)
				exit(255);
			else
				execute_another_function(main, command->pipe);
		}
	}
}

int		ft_exit(t_command *command, t_main *main)
{
	int		error;
	char	*temp;

	check_redirect(command);
	dup2(main->main_1, 1);
	if (command->args[1] != NULL)
	{
		ft_exit_support(command->args[1], command, main);
		error = ft_atoi(command->args[1]);
	}
	else
		error = main->status;
	if (get_sizeof_args(command->args) > 2)
	{
		ft_putstr_fd("exit\n", 2);
		send_custom_error("Too many arguments");
		main->status = 1;
	}
	else
	{
		if (command->pipe == NULL)
		{
			ft_putstr_fd("exit\n", 2);
			exit(error);
		}
		else
		{
			temp = command->pipe->command_str;
			command->pipe->command_str = get_command_path(main, command->pipe->command_str);
			free(temp);
			execute_another_function(main, command->pipe);
		}
	}
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
		ft_putstr_fd(main->env[i], 1);
		ft_putstr_fd("\n", 1);
	}
	ft_get_pipe(main, command->pipe, 1);
	return (1);
}

void	ft_get_pipe(t_main *main, t_command *command, int type)
{
	int		pfd[2];
	char	*temp;

	dup2(main->main_1, 1);
	if (command != NULL && command->command_str != NULL)
	{
		if (type == 0)
		{
			pipe(pfd);
			dup2(pfd[0], 0);
			dup2(pfd[1], 1);
		}
		else
		{
			temp = command->command_str;
			command->command_str = get_command_path(main, command->command_str);
			free(temp);
			execute_another_function(main, command);
		}
	}
	dup2(main->main_0, 0);
}

int		ft_echo(t_command *command, t_main *main)
{
	int		i;
	int		stop;

	i = 0;
	if ((stop = 0) || command->args[1] == NULL)
	{
		ft_putchar_fd('\n', 1);
		return (1);
	}
	ft_get_pipe(main, command->pipe, 0);
	check_redirect(command);
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
