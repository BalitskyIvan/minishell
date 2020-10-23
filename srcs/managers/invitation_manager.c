/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invitation_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:02:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/22 18:17:18 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char			*random_color(void)
{
	static int	color = 0;
	static char	colors[8][10] = {"\033[0;30m", "\033[0;31m",\
	"\033[0;32m", "\033[0;33m", "\033[0;34m",\
	"\033[0;35m", "\033[0;36m", "\033[0;37m"};

	if (color == 7)
		color = 0;
	color++;
	return (colors[color]);
}

void			send_invitation(void)
{
	char		*color;
	static int	word = 0;

	color = random_color();
	ft_putstr_fd(color, 1);
	ft_putstr_fd(BOLD, 1);
	if (word == 2)
		word = 0;
	if (word == 0)
		ft_putstr_fd("ПРОВЕР❯ ", 1);
	else
		ft_putstr_fd("ОЧКА  ❯	", 1);
	ft_putstr_fd(RESET, 1);
	word++;
}

void			check_signals(int ret, t_main *main)
{
	if (ret == 777777)
	{
		ft_putstr_fd("exit\n", 1);
		exit(main->status);
	}
}

void			wait_string(t_main *main)
{
	char		*line;
	int			ret;
	t_command	*first;

	while ((ret = get_next_line(0, &line)) != -1)
	{
		g_sigint = 0;
		check_signals(ret, main);
		if (g_sigquit && (g_sigquit = 0) == 0)
			free(line);
		else
		{
			if (parse_commands(main, line, 0))
			{
				first = main->command;
				execute(main);
				free_command_list(first);
			}
			free(line);
			line = NULL;
		}
		if (!g_sigint)
			send_invitation();
	}
	free(line);
}
