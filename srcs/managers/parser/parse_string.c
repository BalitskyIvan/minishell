/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:42:34 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 20:43:59 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	white_string(void)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) != 0)
	{
		ft_putstr_fd("ERROR: Command not found!\n", 0);
		// printf("%s\n", line);
		free(line);
		get_invitation();
	}
}
