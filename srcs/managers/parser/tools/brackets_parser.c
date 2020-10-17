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
		*dst = ft_strjoin(*dst, ft_itoa(main->status));
		*start = begin + 1;
		return ;
	}
	key = ft_substr(str, begin, end - begin);
	res = get_env_value(main, key);
	if (res != NULL)
	{
		*dst = ft_strjoin(*dst, res);
		free(res);
	}
	*start = end;
	free(key);
}

int			skip_single_brackets(char **dst, char *str, int start)
{
	char	*c;

	if (str[start] == '\'')
		start++;
	c = (char*)malloc(2 * sizeof(char));
	c[1] = '\0';
	while (str[start] != '\'' && str[start])
	{
		c[0] = str[start];
		*dst = ft_strjoin(*dst, c);
		start++;
	}
	free(c);
	if (str[start] == '\'')
		return (start + 1);
	return (0);
}

static int	skip_shield(char **c, char **dst, char *str, int *start)
{
	(*c)[0] = str[*start];
	if (str[*start] == '\\')
	{
		if (str[*start + 1] == '"')
		{
			free(*c);
			return (0);
		}
		if (str[*start + 1] == '\\')
			*start = *start + 1;
		else
		{
			if (str[*start + 1] != '$')
				*dst = ft_strjoin(*dst, *c);
			*start = *start + 1;
			(*c)[0] = str[*start];
		}
	}
	return (1);
}

int			skip_double_brackets(char **dst, char *str, int start, t_main *main)
{
	char	*c;

	c = (char*)malloc(2 * sizeof(char));
	c[1] = '\0';
	if (str[start] == '"')
		start++;
	while (str[start] != '"' && str[start])
	{
		if (str[start] == '$')
			get_environment_variable(dst, str, &start, main);
		else
		{
			if (!skip_shield(&c, dst, str, &start))
				return (0);
			*dst = ft_strjoin(*dst, c);
			start++;
		}
	}
	free(c);
	if (str[start] == '"')
		return (start + 1);
	return (0);
}
