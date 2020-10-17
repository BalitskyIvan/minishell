/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:04:49 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/12 20:26:38 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_command	*catch_tree_commands(char *str, int *start, t_main *main)
{
	t_command	*new;

	new = NULL;
	new = catch_pipe(str, start, main);
	if (new == NULL)
		new = catch_redirect(str, start, main);
	if (new == NULL)
		new = catch_back_redirect(str, start, main);
	if (new == NULL)
		new = catch_double_redirect(str, start, main);
	return (new);
}

static t_command		*catch_command(char *str, int *start, t_main *main)
{
	t_command	*new;

	while (str[*start] == ' ')
		*start = *start + 1;
	new = catch_endpoint(str, start, main);
	if (new == NULL)
		new = catch_tree_commands(str, start, main);
	return (new);
}

static int				parse_commands(t_main *main, char *str, int start)
{
	t_command	*current;
	t_command	*last_pipe;
	t_command	*last_redirect;
	t_command	*copy;

	if (*str == '\0')
		return (0);
	last_pipe = NULL;
	last_redirect = NULL;
	current = catch_command(str, &start, main);
	if (current->undefined_arg != 0)
	{
		ft_putstr_fd("double cuote or something like this catched\n", 0);
		free_command_list(current);
		return (0);
	}
	main->command = current;
	while (str[start] != '\0')
	{
		copy = catch_command(str, &start, main);
		if (copy->undefined_arg != 0)
		{
			ft_putstr_fd("double cuote or something like this catched\n", 0);
			free_command_list(main->command);
			return (0);
		}
		if (copy->endpoint_type == 0)
		{
			current->next = copy;
			current = current->next;
			last_pipe = NULL;
			last_redirect = NULL;
		}
		if (copy->endpoint_type == 1)
		{
			if (last_pipe == NULL)
			{
				last_pipe = copy;
				current->pipe = last_pipe;
				last_redirect = NULL;
			}
			else
			{
				last_redirect = NULL;
				last_pipe->pipe = copy;
				last_pipe = last_pipe->pipe;
			}
		}
		if (copy->endpoint_type == 2)
		{
			if (last_redirect == NULL)
			{
				last_redirect = copy;
				if (last_pipe != NULL)
					last_pipe->redirect = last_redirect;
				else
					current->redirect = last_redirect;
			}
			else
			{
				last_redirect->redirect = copy;
				last_redirect = last_redirect->redirect;
			}
		}
	}
	return (1);
}

void				wait_string(t_main *main)
{
	char	*line;
	main->main_0 = dup(0);
	main->main_1 = dup(1);
	main->status = 0;
	while (get_next_line(0, &line) != 0)
	{
		if (parse_commands(main, line, 0))
			execute(main);
		free(line);
		line = NULL;
		send_invitation();
	}
}
