/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:21:52 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/17 14:15:39 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void		get_environment_variable(char **dst, char *str, int *start,
t_main *main)
{
	int		begin;
	int		end;
	char	*key;
	char	*res;

	begin = *start;
	if (str[*start] == '$')
		begin++;
	end = begin;
	while (str[end] != ' ' && str[end] != '"' && str[end] != '\'' &&
	str[end] != '\\' && !is_valid_point_catched(str[end]) && str[end])
		end++;
	if (str[begin] == '?')
	{
		join_str(dst, ft_itoa(main->status));
		*start = begin + 1;
		return ;
	}
	key = ft_substr(str, begin, end - begin);
	res = get_env_value(main, key);
	if (res != NULL)
		join_str(dst, res);
	*start = end;
	free(key);
}

int			skip_single_brackets(char **dst, char *str, int start)
{
	char	*c;

	if (str[start] == '\'')
		start++;
	while (str[start] != '\'' && str[start])
	{
		c = (char*)malloc(2 * sizeof(char));
		c[1] = '\0';
		c[0] = str[start];
		join_str(dst, c);
		start++;
	}
	if (str[start] == '\'')
		return (start + 1);
	return (0);
}

static int	skip_shield(char **dst, char *str, int *start)
{
	char *c;

	if (str[*start] == '\\')
	{
		if (str[*start + 1] == '"' && str[*start + 2] != '"')
			return (0);
		if (str[*start + 1] == '\\')
			*start = *start + 1;
		else
		{
			if (str[*start + 1] != '$')
			{
				c = (char*)malloc(2 * sizeof(char));
				c[1] = '\0';
				c[0] = str[*start];
				join_str(dst, c);
			}
			*start = *start + 1;
		}
	}
	return (1);
}

int			skip_double_brackets(char **dst, char *str, int start, t_main *main)
{
	char	*c;

	if (str[start] == '"')
		start++;
	while (str[start] != '"' && str[start])
	{
		if (str[start] == '$')
			get_environment_variable(dst, str, &start, main);
		else
		{
			if (!skip_shield(dst, str, &start))
				return (0);
			c = (char*)malloc(2 * sizeof(char));
			c[1] = '\0';
			c[0] = str[start];
			join_str(dst, c);
			start++;
		}
	}
	if (str[start] == '"')
		return (start + 1);
	return (0);
}
