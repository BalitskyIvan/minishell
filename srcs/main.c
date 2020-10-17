/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:29:49 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/17 14:03:58 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_main	main;

	(void)argc;
	main = global_init(argv, env);
	copy_env(env, &main);
	errno = 0;
	wait_string(&main);
	return (0);
}
