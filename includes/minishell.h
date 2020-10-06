/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:28:19 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/06 16:38:25 by mklotz           ###   ########.fr       */
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

typedef struct			s_command
{
	char				*command_str;
    char				**args;
	int					option;
	struct s_command	*next;
	struct s_command	*prev;
}						t_command;

typedef struct			s_main
{
	char				**argv;
	char				**env;
	t_command			*command;
}						t_main;

void					send_invitation(void);
void					send_error(void);
t_main					global_init(char *argv[], char *env[]);
t_command				*get_first_command(t_command *command);
t_command				*get_last_command(t_command *command);
t_command				*get_command(t_main *main, int elem);
void					command_add_front(t_command *command, t_main *main);
void					command_add_back(t_command *command, t_main *main);
t_command				*init_command_basic(void);
t_command				*create_command(char *command, char **args, int is_pipe);
void					wait_string(t_main *main);
int						execute_another_function(t_main *main);
void					send_custom_error(char *str);
char					*get_env_value(t_main *main, char *key);
char					*get_command_path(t_main *main, char *command);
void					execute(t_main *main, char *cmd);
int						ft_cd(t_main *main);
void					ft_exit(t_main *main);
int						ft_env(t_main *main);

#endif