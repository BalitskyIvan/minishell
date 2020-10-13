/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:59:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/13 14:10:33 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_file(char *file, int type)
{
	int		fd;

	errno = 0;
	if (type == 1)
		fd = open(file, O_RDWR | O_CREAT, O_EXCL | S_IWRITE, S_IREAD);
	else if (type == 2)
		fd = open(file, O_RDWR | O_CREAT, O_EXCL | S_IWRITE, S_IREAD, O_APPEND);
	// send_error();
	// printf("FD = %d		NAME = %s\n", fd, file);
	return (fd);
}
