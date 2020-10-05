/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:42:34 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 23:00:24 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	parse_string(t_main *main, char *str)
{
	char	*patch;

	main->com->args = ft_split(str, ' ');
	patch = get_command_patch(main, main->com->args[0]);
	main->com->command = patch;
	execute_another_function(main);
}

void	wait_string(t_main *main)
{
	char	*line;

	while (get_next_line(0, &line) != 0)
	{
		parse_string(main, line);
		free(line);
		line = NULL;
		get_invitation();
	}
}
