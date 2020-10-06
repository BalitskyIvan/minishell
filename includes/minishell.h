/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:28:19 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/06 03:11:00 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>

# include "../utils/libft/libft.h"
# include "../utils/gnl/get_next_line.h"

# define BOLD "\033[1m"
# define RESET "\033[0m"

# define ERROR "Error:\n"
# define SYNTAX_ERROR "Syntax error: "

typedef struct		s_coma
{
	char			*command;
    char			**args;
	int				is_pipe;
	struct s_coma	*next;
	struct s_coma	*prev;
}					t_coma;

typedef struct		s_main
{
	char			**argv;
	char			**env;
	t_coma			*com;
}					t_main;

void				get_invitation(void);
void				send_error(void);
t_main				global_init(char *argv[], char *env[]);
t_coma				*coma_get_first(t_coma *coma);
t_coma				*coma_get_last(t_coma *coma);
t_coma				*coma_get_element(t_main *main, int elem);
void				coma_add_front(t_coma *coma, t_main *main);
void				coma_add_back(t_coma *coma, t_main *main);
t_coma				*init_coma_basic(void);
t_coma				*coma_create(char *command, char **args, int is_pipe);
void				wait_string(t_main *main);
int					execute_another_function(t_main *main);
void				send_custom_error(char *str);
char				*get_env_value(t_main *main, char *key);
char				*get_command_patch(t_main *main, char *command);
void				execute_managers(t_main *main, char *cmd);
int					ft_cd(t_main *main);
void				ft_exit(t_main *main);
int					ft_env(t_main *main);

#endif