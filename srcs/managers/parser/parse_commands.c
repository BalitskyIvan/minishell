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

static t_command	*catch_tree_commands(t_command *current, char *str,
int *start, t_main *main)
{
	t_command	*new;

	new = catch_pipe(str, start, main);
	if (new == NULL)
		new = catch_redirect(str, start, main);
	if (new == NULL)
		new = catch_back_redirect(str, start, main);
	if (new == NULL)
		new = catch_double_redirect(str, start, main);
	return (new);
}

t_command			*catch_command(t_command *current, char *str,
int *start, t_main *main)
{
	t_command	*new;

	while (str[*start] == ' ')
		*start = *start + 1;
	new = catch_endpoint(str, start, main);
	if (new == NULL)
		new = catch_tree_commands(current, str, start, main);
	else
		new->prev = current;
	return (new);
}

void				parse_commands(t_main *main, char *str)
{
	t_command	*current;
	t_command	*first;
	int			start;
	int			now;

	start = 0;
	now = 0;
	if (*str == '\0')
		return ;
	current = catch_command(NULL, str, &start, main);
	first = current;
	while (str[start] != '\0')
	{
		current->next = catch_command(current, str, &start, main);
		current = current->next;
	}
	main->command = first;
	// print_commands(first, "EP");
}

void				wait_string(t_main *main)
{
	char	*line;

	while (get_next_line(0, &line) != 0)
	{
		parse_commands(main, line);
		execute(main);
		free(line);
		line = NULL;
		send_invitation();
	}
}

