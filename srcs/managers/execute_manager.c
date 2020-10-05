/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:32:33 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 22:24:10 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		execute_another_function(t_main *main)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		status = execve(main->com->command, main->com->args, main->env);
		if (status == -1)
			send_custom_error("Command not found!");
	}
	else if (pid < 0)
		send_error();
	else
		wait(&pid);
	return (0);
}
