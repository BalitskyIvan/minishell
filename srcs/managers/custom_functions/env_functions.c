/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:17:44 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/23 18:15:57 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void		ft_unset_env(t_main *main, char *arg)
{
	char	*temp;

	if (ft_strnstr(arg, "=", -1) == NULL)
	{
		if ((temp = get_env_value(main, arg)) != NULL)
		{
			free(temp);
			unset_env(main, arg);
		}
	}
	else
		send_custom_error("Error argument!");
}

void		ft_export_env(t_main *main, char *arg)
{
	char	**temp;

	temp = ft_split(arg, '=');
	ft_unset_env(main, temp[0]);
	free_args(temp);
	export_env(main, arg);
}

int			env_manager(t_main *main, t_command *command, int type)
{
	int		i;

	i = 0;
	ft_get_pipe(main, command->pipe, 0);
	check_redirect(command);
	if (type == 0)
	{
		if (command->args[1] == NULL)
			print_export(main);
		else
			while (command->args[++i] != NULL)
				ft_export_env(main, command->args[i]);
	}
	else
	{
		while (command->args[++i] != NULL)
			ft_unset_env(main, command->args[i]);
	}
	ft_get_pipe(main, command->pipe, 1);
	return (1);
}

int			ft_pwd(t_main *main, t_command *command)
{
	char	*temp;

	ft_get_pipe(main, command->pipe, 0);
	check_redirect(command);
	temp = getcwd(NULL, 2000);
	ft_putstr_fd(temp, 1);
	ft_putstr_fd("\n", 1);
	free(temp);
	ft_get_pipe(main, command->pipe, 1);
	return (1);
}
