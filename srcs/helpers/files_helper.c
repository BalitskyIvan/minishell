/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:59:22 by mklotz            #+#    #+#             */
/*   Updated: 2020/10/13 12:43:39 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_file(char *file, char type)
{
	int		fd;

	if (type == '0')
		fd = open(file, O_RDWR | O_CREAT);
	else
		fd = open(file, O_RDWR | O_CREAT, O_APPEND);
	// send_error();
	return (fd);
}
