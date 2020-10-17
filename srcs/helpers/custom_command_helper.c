/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_command_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:42:34 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/17 11:35:41 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*check_acting_patch(t_main *main, char *command)
{
	char	*result;
	char	*temp;
	char	*temp2;
	int		i;

	result = NULL;
	i = -1;
	temp = get_env_value(main, "PWD");
	temp2 = ft_strjoin(temp, "/");
	free(temp);
	result = ft_strjoin(temp2, command);
	if (access(result, 1) == 0)
		return (result);
	free(result);
	if (access(command, 1) == 0)
		return (command);
	return (NULL);
}

char	*get_command_path(t_main *main, char *command)
{
	char	*result;
	char	*temp;
	char	**paths;
	int		i;

	result = NULL;
	i = -1;
	temp = get_env_value(main, "PATH");
	paths = ft_split(temp, ':');
	free(temp);
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		result = ft_strjoin(temp, command);
		free(temp);
		if (access(result, 1) == 0)
			break ;
		else
		{
			free(result);
			result = NULL;
		}
	}
	return ((result == NULL) ? check_acting_patch(main, command) : result);
}
