/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_custom_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 03:06:49 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/12 20:38:03 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int		ft_cd(t_command *command)
{
	char	*patch;
	char	new_patch[200];

	if (command->args[1] != NULL)
		patch = command->args[1];
	else
	{
		send_custom_error("Not path");
		return (1);
	}
	if (patch[0] != '/')
		patch = ft_strjoin(getcwd(new_patch, 200), patch);
	if (chdir(patch) == -1)
			send_custom_error("invalid path");
	return (1);
}

void	ft_exit(t_command *command)
{
	int		error;

	if (command->args[1] != NULL)
		error = ft_atoi(command->args[1]);
	else
		error = 0;
	printf("exit\n");
	exit(error);
}

int		ft_env(t_main *main)
{
	int		i;

	i = -1;
	while (main->env[++i])
			printf("%s\n", main->env[++i]);
	return (1);
}
