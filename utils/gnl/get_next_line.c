/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 14:44:58 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/20 13:01:58 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	mem_free(char **object)
{
	if (!object || !*object)
		return ;
	free(*object);
	*object = NULL;
}

int		write_line(char **line, char buff[BUFFER_SIZE])
{
	char *temp;

	temp = *line;
	*line = ft_strjoin(*line, buff);
	free(temp);
	temp = NULL;
	if (*line == NULL)
		return (0);
	return (1);
}

int		get_line_of_mem(char **mem, char **line)
{
	char *ptr;
	char *temp;

	if ((ptr = ft_strchr(*mem, '\n')))
	{
		*ptr = '\0';
		if (!(*line = ft_strdup(*mem)))
			return (-1);
		*ptr = '\n';
		temp = *mem;
		if (!(*mem = ft_substr(*mem, ft_strlen(*line) + 1, -1)))
			return (-1);
		mem_free(&temp);
		return (1);
	}
	return (0);
}

int		memory_manager(char **mem, char **line)
{
	int		res;

	*line = NULL;
	if (mem && *mem)
	{
		if ((res = get_line_of_mem(*&mem, *&line)) < 0)
			return (-1);
		else if (res == 1)
			return (1);
		else if (res == 0)
		{
			if (!(*line = ft_strdup(*mem)))
				return (-1);
			mem_free(*&mem);
			if (ft_strlen(*line) == 0)
				mem_free(*&line);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	char		*ptr;
	static char	*mem;

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if ((ret = memory_manager(&mem, *&line)) != 0)
		return ((ret != -1) ? 1 : -1);
	ptr = NULL;
	while (!ptr && (ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = '\0';
			if (!(mem = ft_strdup(++ptr)))
				return (-1);
		}
		if (!(write_line(*&line, buff)))
			return (-1);
	}
	if (*line == NULL)
		*line = ft_strdup("");
	return ((ret || (mem && ft_strlen(mem))) ? 1 : 0);
}
