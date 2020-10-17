/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:33:04 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/12 20:23:06 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_value(t_main *main, char *key)
{
	int		i;
	char	**temp;
	char	*result;

	i = -1;
	result = NULL;
	while (main->env[++i])
	{
		temp = ft_split(main->env[i], '=');
		if (ft_strncmp(temp[0], key, -1) == 0)
		{
			result = ft_strdup(temp[1]);
			free(temp);
		}
	}
	return (result);
}

void	free_env(t_main *main)
{
	int		i;

	i = 0;
	while (main->env[i])
		i++;
	while (i > -1)
		free(main->env[i--]);
	free(main->env);
	main->env = NULL;
}

int		export_env(t_main *main, char *arg)
{
	char	**env;
	int		i;
	
	i = 0;
	env = main->env;
	while (env[i])
		i++;
	main->env = (char **)malloc(i + 2 * sizeof(char *));
	i = -1;
	while (env[++i])
		main->env[i] = ft_strdup(env[i]);
	main->env[i] = ft_strdup(arg);
	main->env[i + 1] = NULL;
	return (1);
}

int		unset_env(t_main *main, char *arg)
{
	char	**env;
	char	**temp;
	int		i;
	int		j;
	
	i = 0;
	env = main->env;
	while (env[i])
		i++;
	main->env = (char **)malloc(i * sizeof(char *));
	i = -1;
	j = 0;
	while (env[++i])
	{
		temp = ft_split(env[i], '=');
		if (ft_strncmp(temp[0], arg, -1) == 0)
			j--;
		else
			main->env[i] = ft_strdup(env[i]);
		j++;
		free(temp);
	}
	main->env[i] = NULL;
	return (1);
}

int		copy_env(char *env[], t_main *main)
{
	int		i;
	
	i = 0;
	while (env[i])
		i++;
	main->env = (char **)malloc(i + 1 * sizeof(char *));
	send_error();
	i = -1;
	while (env[++i])
		main->env[i] = ft_strdup(env[i]);
	main->env[i] = NULL;
	return (1);
}
