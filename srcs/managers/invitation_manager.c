/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invitation_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:02:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/19 14:56:03 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*random_color(void)
{
	static int		color = 0;
	static char		colors[8][10] = {"\033[0;30m", "\033[0;31m",\
	"\033[0;32m", "\033[0;33m", "\033[0;34m",\
	"\033[0;35m", "\033[0;36m", "\033[0;37m"};

	if (color == 7)
		color = 0;
	color++;
	return (colors[color]);
}

void	send_invitation(void)
{
	char			*color;
	static int		word = 0;

	color = random_color();
	ft_putstr_fd(color, 0);
	ft_putstr_fd(BOLD, 0);
	if (word == 2)
		word = 0;
	if (word == 0)
		ft_putstr_fd("ЛУЧШИЙ❯ ", 0);
	else
		ft_putstr_fd("ШЕЛЛ❯	", 0);
	ft_putstr_fd(RESET, 0);
	word++;
}

void	wait_string(t_main *main)
{
	char	*line;
	t_command *first;

	main->main_0 = dup(0);
	main->main_1 = dup(1);
	main->status = 0;
	while (get_next_line(0, &line) != 0)
	{
		if (parse_commands(main, line, 0))
        {
		    first = main->command;
            execute(main);
            free_command_list(first);
        }
		free(line);
		line = NULL;
		send_invitation();
	}
	free(line);
}
