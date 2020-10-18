/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:17:44 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/18 16:22:01 by mklotz           ###   ########.fr       */
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

	if (ft_strnstr(arg, "=", -1) != NULL && arg[0] != '=')
	{
		temp = ft_split(arg, '=');
		ft_unset_env(main, temp[0]);
		free_args(temp);
		export_env(main, arg);
	}
	else
		send_custom_error("Error argument!");
}

int			env_manager(t_main *main, t_command *command, int type)
{
	int		i;

	i = 0;
	if (type == 0)
	{
		while (command->args[++i] != NULL)
			ft_export_env(main, command->args[i]);
	}
	else
	{
		while (command->args[++i] != NULL)
			ft_unset_env(main, command->args[i]);
	}
	return (1);
}

int			ft_pwd(void)
{
	char	*temp;

	temp = getcwd(NULL, 2000);
	printf("%s\n", temp);
	free(temp);
	return (1);
}