/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:10:36 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/17 14:13:28 by mklotz           ###   ########.fr       */
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
	join_str(dst, c);
	start++;
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

	while (str[*start] == ' ')
		*start = *start + 1;
	while (!is_valid_point_catched(str[*start]) && str[*start] &&
			str[*start] != ' ')
	{
		str_start = *start;
		if (!skip_options(dst, str, start, main))
			return (0);
		if (str[*start] && *start == str_start)
		{
			c = (char*)malloc(2 * sizeof(char));
			c[0] = str[*start];
			c[1] = '\0';
			join_str(dst, c);
			*start = *start + 1;
		}
	}
	return (1);
}

static char	**free_pars_args(int args_size, char **args, char *arg)
{
	int i2;

	i2 = 0;
	while (i2 < args_size - 1)
	{
		free(args[i2]);
		i2++;
	}
	free(args);
	free(arg);
	return (NULL);
}

char		**parse_args(int args_size, char *str, int start, t_main *main)
{
	char	**args;
	char	*arg;
	int		i;

	i = 0;
	args = (char **)malloc((args_size + 1) * sizeof(char *));
	args[i] = get_command_str(str, start, main);
	while (str[start] != ' ' && str[start] &&
	!is_valid_point_catched(str[start]))
	{
		start++;
		if (str[start] == '\\')
			start += 2;
	}
	while (!is_valid_point_catched(str[start]) && str[start])
	{
		arg = ft_strdup("");
		if ((skip_brackets(&arg, str, &start, main)))
			write_to_args(arg, args, &i);
		else
			return (free_pars_args(args_size, args, arg));
	}
	args[i + 1] = NULL;
	return (args);
}
