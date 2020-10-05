/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:28:19 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/05 19:02:54 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <stdio.h>
# include <dirent.h>

# include "../utils/libft/libft.h"
# include "../utils/gnl/get_next_line.h"

# define GREEN "\033[32m"
# define RESET "\033[0m"

typedef struct		s_coma
{
	char			*command;
    char			**args;
	int				is_pipe;
	struct s_coma	*next;
	struct s_coma	*prev;
}					t_coma;

#endif