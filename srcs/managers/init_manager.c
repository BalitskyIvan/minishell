/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:05:42 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/18 17:08:46 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_main	global_init(char *argv[], char *env[])
{
	t_main	main;

	g_read_started = 1;
	g_sigquit = 0;
	g_sigint = 0;
	main.argv = argv;
	main.env = env;
	main.command = init_command_basic();
	send_invitation();
	return (main);
}
