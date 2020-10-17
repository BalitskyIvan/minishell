/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:10:36 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/09 13:10:40 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int			skip_shielding(char **dst, char *str, int start)
{
	char *c;

	if (str[start] == '\\')
		start++;
	if (str[start] == '\0')
		return (0);
	c = (char*)malloc(2 * sizeof(char));
	c[1] = '\0';
	c[0] = str[start];
	*dst = ft_strjoin(*dst, c);
	start++;
	free(c);
	return (start);
}

static int	skip_options(char **dst, char *str, int *start, t_main *main)
{
	if (str[*start] == '\'')
		if (!(*start = skip_single_brackets(dst, str, *start)))
			return (0);
	if (str[*start] == '"')
		if (!(*start = skip_double_brackets(dst, str, *start, main)))
			return (0);
	if (str[*start] == '\\')
		if (!(*start = skip_shielding(dst, str, *start)))
			return (0);
	if (str[*start] == '$')
		get_environment_variable(dst, str, start, main);
	return (1);
}

int			skip_brackets(char **dst, char *str, int *start, t_main *main)
{
	int		str_start;
	char	*c;

	*dst = NULL;
	while (str[*start] == ' ')
		*start = *start + 1;
	c = (char*)malloc(2 * sizeof(char));
	c[1] = '\0';
	while (!is_valid_point_catched(str[*start]) && str[*start] &&
			str[*start] != ' ')
	{
		str_start = *start;
		if (!skip_options(dst, str, start, main))
			return (0);
		if (str[*start] && *start == str_start)
		{
			c[0] = str[*start];
			*dst = ft_strjoin(*dst, c);
			*start = *start + 1;
		}
	}
	return (1);
}


char		**parse_args(int args_size, char *str, int start, t_main *main)
{
	char	**args;
	char	*arg;
	int		i;

	i = 0;
	args = (char**)malloc((args_size + 1) * sizeof(char*));
	args[i] = get_command_str(str, start, main);
	while (str[start] != ' ' && str[start] &&
	!is_valid_point_catched(str[start]))
		start++;
	while (!is_valid_point_catched(str[start]) && str[start])
	{
		if ((skip_brackets(&arg, str, &start, main)))
		{
			i++;
			args[i] = arg;
		}
		else
		{
			free_args(args);
			return (NULL);
		}
	}
	args[i + 1] = NULL;
	return (args);
}
