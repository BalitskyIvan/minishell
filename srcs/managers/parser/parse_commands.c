/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:04:49 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/24 15:01:46 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_command	*catch_command(char *str, int *start, t_main *main,
t_command *current)
{
	t_command	*new;

	new = NULL;
	while (str[*start] == ' ')
		*start = *start + 1;
	new = catch_endpoint(str, start, main);
	if (new == NULL)
		new = catch_pipe(str, start, main);
	if (new == NULL && current != NULL)
		new = catch_redirect(str, start, main, current);
	if (new == NULL && current != NULL)
		new = catch_back_redirect(str, start, main, current);
	if (new == NULL && current != NULL)
		new = catch_double_redirect(str, start, main, current);
	return (new);
}

static void			write_if_redir(t_command **current, t_command **last_pipe,
t_command **last_redirect, t_command **copy)
{
	if ((*copy)->endpoint_type == 2)
	{
		if (*last_redirect == NULL)
		{
			*last_redirect = *copy;
			if (*last_pipe != NULL)
				(*last_pipe)->redirect = *last_redirect;
			else
				(*current)->redirect = *last_redirect;
		}
		else
		{
			(*last_redirect)->redirect = *copy;
			(*last_redirect) = (*last_redirect)->redirect;
		}
	}
}

static void			write_if_pipe(t_command **current, t_command **last_pipe,
t_command **last_redirect, t_command **copy)
{
	if ((*copy)->endpoint_type == 1)
	{
		if (*last_pipe == NULL)
		{
			*last_pipe = *copy;
			(*current)->pipe = *last_pipe;
			*last_redirect = NULL;
		}
		else
		{
			(*last_redirect) = NULL;
			(*last_pipe)->pipe = *copy;
			(*last_pipe) = (*last_pipe)->pipe;
		}
	}
}

static void			write_if_endpoint(t_command **current,
t_command **last_pipe, t_command **last_redirect, t_command **copy)
{
	if ((*copy)->endpoint_type == 0)
	{
		(*current)->next = *copy;
		(*current) = (*current)->next;
		(*last_pipe) = NULL;
		(*last_redirect) = NULL;
	}
}

int					parse_commands(t_main *main, char *str, int start)
{
	t_command	*current;
	t_command	*last_pipe;
	t_command	*last_redirect;
	t_command	*copy;

	if (*str == '\0' || (last_pipe = NULL) != NULL)
		return (0);
	last_redirect = NULL;
	current = catch_command(str, &start, main, NULL);
	if (check_parser_error(current, current, 0))
		return (0);
	main->command = current;
	while (str[start] != '\0')
	{
		if (last_pipe != NULL)
			copy = catch_command(str, &start, main, last_pipe);
		else
			copy = catch_command(str, &start, main, current);
		if (check_parser_error(main->command, copy, 1))
			return (0);
		write_if_endpoint(&current, &last_pipe, &last_redirect, &copy);
		write_if_pipe(&current, &last_pipe, &last_redirect, &copy);
		write_if_redir(&current, &last_pipe, &last_redirect, &copy);
	}
	return (1);
}
