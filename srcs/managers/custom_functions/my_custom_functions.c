/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_custom_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:06:49 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/17 13:35:39 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exit(t_command *command, t_main *main)
{
	int		error;

	if (command->args[1] != NULL)
		error = ft_atoi(command->args[1]);
	else
		error = main->status;
	printf("exit\n");
	exit(error);
}

int		ft_env(t_main *main)
{
	int		i;

	i = -1;
	while (main->env[++i])
	{
		ft_putstr_fd(main->env[i], 1);
		ft_putstr_fd("\n", 1);
	}
	return (1);
}

void	ft_echo_get_pipe(t_main *main, t_command *command, int type)
{
	int		pfd[2];

	if (command->pipe != NULL)
	{
		if (type == 0)
		{
			pipe(pfd);
			dup2(pfd[1], 1);
			dup2(pfd[0], 0);
		}
		else
		{
			command->command_str = get_command_path(main, command->command_str);
			execute_another_function(main, command);
		}
	}
}

int		ft_echo(t_command *command, t_main *main)
{
	int		i;

	i = 0;
	if (command->args[1] == NULL)
	{
		ft_putchar_fd('\n', 1);
		return (1);
	}
	ft_echo_get_pipe(main, command, 0);
	check_redirect(command);
	while (command->args[++i])
	{
		if (i == 1 && ft_strncmp(command->args[1], "-n", -1) == 0)
			continue ;
		ft_putstr_fd(command->args[i], 1);
		if (command->args[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
	}
	if (ft_strncmp(command->args[1], "-n", -1) != 0)
		ft_putchar_fd('\n', 1);
	dup2(main->main_1, 1);
	ft_echo_get_pipe(main, command, 1);
	dup2(main->main_0, 0);
	return (1);
}
