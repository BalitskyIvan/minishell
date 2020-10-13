/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:28:19 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/13 14:34:32 by mklotz           ###   ########.fr       */
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

# define ERROR "Error"
# define SYNTAX_ERROR "Syntax error: "

typedef struct			s_command
{
	char				*command_str;
	char				**args;
	int					redirect_type;
	int					undefined_arg;
	struct s_command	*pipe;
	struct s_command	*redirect;
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
int						is_valid_point_catched(char c);
t_main					global_init(char *argv[], char *env[]);
t_command				*get_first_command(t_command *command);
t_command				*get_last_command(t_command *command);
t_command				*get_command(t_main *main, int elem);
void					command_add_front(t_command *command, t_main *main);
void					command_add_back(t_command *command, t_main *main);
t_command				*init_command_basic(void);
t_command				*create_command(char *command,
char **args, int is_pipe);
void					wait_string(t_main *main);
int						execute_another_function(t_main *main, t_command *command);
void					send_custom_error(char *str);
char					*get_env_value(t_main *main, char *key);
char					*get_command_path(t_main *main, char *command);
void					execute(t_main *main);
int						ft_cd(t_command *command);
void					ft_exit(t_command *command);
int						ft_env(t_main *main);
char					*get_command_str(char *str, int start, t_main *main);
char					**get_args_str(char *str, int start, t_main *main);
t_command				*create_obj(char *command_string, char **args);
t_command				*catch_endpoint(char *str, int *start, t_main *main);
void					print_commands(t_command *command, char *dsc);
t_command				*catch_command(t_command *current, char *str,
						int *start, t_main *main);
t_command				*catch_pipe(char *str, int *start, t_main *main);
t_command				*catch_redirect(char *str, int *start, t_main *main);
t_command				*catch_back_redirect(char *str, int *start,
t_main *main);
t_command				*catch_double_redirect(char *str, int *start,
t_main *main);
char					**parse_args(int args_size, char *str,
int start, t_main *main);
int						skip_single_brackets(char **dst, char *str, int start);
int						skip_double_brackets(char **dst, char *str,
int start, t_main *main);
void					get_environment_variable(char **dst, char *str,
int *start, t_main *main);
int						skip_brackets(char **dst, char *str,
int *start, t_main *main);
int						copy_env(char *env[], t_main *main);
int						unset_env(t_main *main);
int						export_env(t_main *main);
int						get_file(char *file, int type);
int						check_redirect(t_command *command, int *fd);

#endif
