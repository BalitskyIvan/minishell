/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 22:44:22 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/07 22:44:27 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	get_args_size(char *str, int start)
{
	int	res;

	res = 1;
	while (!is_valid_point_catched(str[start]) && str[start])
	{
		if (str[start] == '\\')
			start += 2;
		if (str[start] != ' ')
		{
			while (!is_valid_point_catched(str[start]) && str[start] &&
			str[start] != ' ')
			{
				start++;
				if (str[start] == '\\')
					start += 2;
			}
			res++;
		}
		else
			start++;
	}
	return (res);
}

static int	skip_to_args(char *str, int start)
{
	int	end;

	end = start;
	while (str[end] != ' ' && str[end])
	{
		end++;
		if (str[end] == '\\')
			end += 2;
	}
	start = end;
	while (str[start] == ' ' && str[start])
		start++;
	return (start);
}

char		*get_command_str(char *str, int start, t_main *main)
{
	char	*res;
	int		s;

	s = start;
	res = ft_strdup("");
	if (!skip_brackets(&res, str, &s, main))
	{
		free(res);
		return (NULL);
	}
	else
		return (res);
}

char		**get_args_str(char *str, int start, t_main *main)
{
	int		end;
	char	**args;
	int		args_size;

	end = skip_to_args(str, start);
	args_size = get_args_size(str, end);
	args = parse_args(args_size, str, start, main);
	return (args);
}
