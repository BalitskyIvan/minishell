/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_command_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:42:34 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/19 19:26:52 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*check_acting_patch(char *command)
{
	char	*result;
	char	*temp;
	char	*temp2;
	int		i;

	result = NULL;
	i = -1;
	temp = getcwd(NULL, 2000);
	temp2 = ft_strjoin(temp, "/");
	free(temp);
	result = ft_strjoin(temp2, command);
	free(temp2);
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
	if ((temp = get_env_value(main, "PATH")) == NULL)
		return (NULL);
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
	free_args(paths);
	return ((result == NULL) ? check_acting_patch(command) : result);
}
