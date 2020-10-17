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
	{
		ft_putstr_fd(main->env[i], 1);
		ft_putstr_fd("\n", 1);
	}
	return (1);
}
