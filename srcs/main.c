/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:29:49 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/18 16:54:02 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			g_read_started;
int			g_sigquit;
int			g_sigint;

void		ft_sigint_ignore(void)
{
	if (g_read_started)
	{
		ft_putstr_fd("\b\b  \b\b\n", 1);
		send_invitation();
	}
	else
		ft_putstr_fd("\n", 1);
	g_sigint = 1;
}

void		ft_sigquit_ignore(void)
{
	g_sigquit = 1;
	ft_putstr_fd("exit\n", 1);
	ft_putstr_fd("\b\b  \b\b", 1);
	exit(0);
}

int			main(int argc, char *argv[], char *env[])
{
	t_main	main;

	(void)argc;
	signal(SIGINT, (void*)ft_sigint_ignore);
	signal(SIGQUIT, (void*)ft_sigquit_ignore);
	main = global_init(argv, env);
	copy_env(env, &main);
	errno = 0;
	wait_string(&main);
	return (0);
}
