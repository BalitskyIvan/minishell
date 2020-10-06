/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:42:34 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/06 00:06:45 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	parse_string(t_main *main, char *str)
{
	execute_managers(main, str);
}

void	wait_string(t_main *main)
{
	char	*line;

	while (get_next_line(0, &line) != 0)
	{
		parse_string(main, line);
		free(line);
		line = NULL;
		send_invitation();
	}
}
