/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:33:04 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 22:42:08 by mklotz           ###   ########.fr       */
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
