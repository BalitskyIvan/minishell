/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:33:04 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/18 16:52:16 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*get_env_value(t_main *main, char *key)
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
			if (temp[1] == NULL)
				result = ft_strdup("test");
			else
				result = ft_strdup(temp[1]);
			free_args(temp);
            break ;
		}
		free_args(temp);
	}
	return (result);
}

int			export_env(t_main *main, char *arg)
{
	char	**temp;
	int		i;
	int		len;

	i = -1;
	len = get_sizeof_args(main->env);
	temp = (char **)malloc((len + 2) * sizeof(char *));
	while (++i < len)
		temp[i] = ft_strdup(main->env[i]);
	temp[i] = ft_strdup(arg);
	temp[i + 1] = 0;
	free_args(main->env);
	main->env = temp;
	return (1);
}

int			unset_env(t_main *main, char *arg)
{
	char	**temp;
	char	**ptr;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	len = get_sizeof_args(main->env);
	temp = (char **)malloc((len) * sizeof(char *));
	while (++i < len)
	{
	    ptr = ft_split(main->env[i], '=');
		if (ft_strncmp(ptr[0], arg, -1) == 0)
		{
			continue ;
			free_args(ptr);
		}
		free_args(ptr);
		temp[j++] = ft_strdup(main->env[i]);
	}
	temp[j] = 0;
	free_args(main->env);
	main->env = temp;
	return (1);
}

int			copy_env(char *env[], t_main *main)
{
	int		len;
	int		i;
	
	i = -1;
	len = get_sizeof_args(env);
	main->env = (char **)malloc((len + 1) * sizeof(char *));
	while (++i < len)
		main->env[i] = ft_strdup(env[i]);
	main->env[i] = 0;
	return (1);
}
