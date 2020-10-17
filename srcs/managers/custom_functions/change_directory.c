/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:44:21 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/17 14:04:14 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	get_sizeof_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int			change_directory(t_command *command, t_main *main)
{
	char	*path;
	char	*new_path;

	path = get_command_path(main, get_env_value(main, "PWD"));
	new_path = "PWD=";
	if (command->command_str[0] == '/')
	{
		if (access(command->command_str, 1) == 0)
			return (0);
		ft_strjoin(new_path, command->command_str);
		free(path);
	}
	unset_env(main, "PWD");
	export_env(main, new_path);
	return (1);
}
