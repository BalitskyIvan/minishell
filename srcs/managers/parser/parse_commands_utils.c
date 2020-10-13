/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:05:20 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/06 16:05:25 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_command	*catch_endpoint(char *str, int *start, t_main *main)
{
	t_command	*new;
	int			end;
	int			iterator;

	iterator = *start;
	while (!is_valid_point_catched(str[iterator]) && str[iterator] != '\0')
		iterator++;
	if ((iterator == *start && str[iterator] != ';')
	|| (str[iterator] != '\0' && str[iterator] != ';'))
		return (NULL);
	if (str[iterator] == ';')
		iterator++;
	new = _create(get_command_str(str, *start, main),
	get_args_str(str, *start, main));
	*start = iterator;
	return (new);
}

t_command	*catch_pipe(char *str, int *start, t_main *main)
{
	t_command	*new;
	int			end;
	int			iterator;

	iterator = *start;
	while (!is_valid_point_catched(str[iterator]) && str[iterator] != '\0')
		iterator++;
	if (str[iterator] != '|')
		return (NULL);
	new = _create(get_command_str(str, *start, main),
	get_args_str(str, *start, main));
	iterator++;
	*start = iterator;
	new->pipe = catch_command(new, str, start, main);
	return (new);
}

t_command	*catch_redirect(char *str, int *start, t_main *main)
{
	t_command	*new;
	int			end;
	int			iterator;

	iterator = *start;
	while (!is_valid_point_catched(str[iterator]) && str[iterator] != '\0')
		iterator++;
	if (str[iterator] == '\0')
		return (NULL);
	if (str[iterator] != '>' || str[iterator + 1] == '>')
		return (NULL);
	new = _create(get_command_str(str, *start, main),
	get_args_str(str, *start, main));
	iterator++;
	*start = iterator;
	new->redirect = catch_command(new, str, start, main);
	return (new);
}

t_command	*catch_back_redirect(char *str, int *start, t_main *main)
{
	t_command	*new;
	int			end;
	int			iterator;

	iterator = *start;
	while (!is_valid_point_catched(str[iterator]) && str[iterator] != '\0')
		iterator++;
	if (str[iterator] != '<')
		return (NULL);
	new = _create(get_command_str(str, *start, main),
	get_args_str(str, *start, main));
	iterator++;
	*start = iterator;
	new->back_redirect = catch_command(new, str, start, main);
	return (new);
}

t_command	*catch_double_redirect(char *str, int *start, t_main *main)
{
	t_command	*new;
	int			end;
	int			iterator;

	iterator = *start;
	while (!is_valid_point_catched(str[iterator]) && str[iterator] != '\0')
		iterator++;
	if (str[iterator] != '>' && str[iterator + 1] != '>')
		return (NULL);
	new = _create(get_command_str(str, *start, main),
	get_args_str(str, *start, main));
	iterator += 2;
	*start = iterator;
	new->double_redirect = catch_command(new, str, start, main);
	return (new);
}