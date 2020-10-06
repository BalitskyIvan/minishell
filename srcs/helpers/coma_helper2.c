/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coma_helper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:32:00 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/05 20:51:34 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_coma	*coma_create(char *command, char **args, int is_pipe)
{
	t_coma	*coma;

	coma = init_coma_basic();
	coma->args = args;
	coma->command = command;
	coma->is_pipe = is_pipe;
	return (coma);
}
