/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:59:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/13 14:44:57 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_file(char *file, int type)
{
	int		fd;

	errno = 0;
	if (type == 1)
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IWRITE | S_IREAD);
	else if (type == 2)
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, S_IWRITE | S_IREAD);
	else if (type == 3)
		fd = open(file, O_RDONLY);
	send_error();
	return (fd);
}
