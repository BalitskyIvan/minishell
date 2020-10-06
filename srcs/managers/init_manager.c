/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:05:42 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 20:42:14 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_coma	*init_coma_basic(void)
{
	t_coma		*coma;

	if ((coma = (t_coma *)malloc(sizeof(t_coma))) == NULL)
		send_error();
	coma->args = NULL;
	coma->command = NULL;
	coma->is_pipe = 0;
	coma->next = NULL;
	coma->prev = NULL;
	return (coma);
}

t_main	global_init(char *argv[], char *env[])
{
	t_main		main;

	main.argv = argv;
	main.env = env;
	main.com = init_coma_basic();
	get_invitation();
	return (main);
}
