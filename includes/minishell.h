/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:28:19 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/20 19:31:44 by mklotz           ###   ########.fr       */
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

extern int		g_read_started;
extern int		g_sigquit;
extern int		g_sigint;

typedef struct			s_command
{
	char				*command_str;
	char				**args;
	int					redirect_type;
	int					undefined_arg;
	int					endpoint_type;
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
	int					main_0;
	int					main_1;
	int					status;
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
int						execute_another_function(t_main *main,
t_command *command);
void					send_custom_error(char *str);
char					*get_env_value(t_main *main, char *key);
char					*get_command_path(t_main *main, char *command);
void					execute(t_main *main);
int						change_directory(t_command *command, t_main *main);
int						ft_exit(t_command *command, t_main *main);
int						ft_env(t_main *main, t_command *command);
char					*get_command_str(char *str, int start, t_main *main);
char					**get_args_str(char *str, int start, t_main *main);
t_command				*create_obj(char *command_string, char **args);
t_command				*catch_endpoint(char *str, int *start, t_main *main);
void					print_commands(t_command *command, char *dsc);
t_command				*catch_pipe(char *str, int *start, t_main *main);
t_command				*catch_redirect(char *str, int *start, t_main *main,
                             t_command *current);
t_command				*catch_back_redirect(char *str, int *start,
t_main *main, t_command *current);
t_command				*catch_double_redirect(char *str, int *start,
t_main *main, t_command *current);
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
int						unset_env(t_main *main, char *arg);
int						export_env(t_main *main, char *arg);
int						get_file(char *file, int type);
int						check_redirect(t_command *command);
int						get_pipe_main(t_main *main, t_command *command,
int pfd[2]);
int						get_pipe_support(t_main *main, t_command *command,
int pfd[2]);
int						check_pipe(t_main *main, t_command *command,
int pfd[2]);
void					free_command_list(t_command *command);
void					free_args(char **args);
int						ft_echo(t_command *command, t_main *main);
t_command				*get_null_command(int undef);
int						get_sizeof_args(char **args);
int						check_parser_error(t_command *start,
t_command *current, int mode);
int						parse_commands(t_main *main, char *str, int start);
void					join_str(char **dst, char *c);
int						env_manager(t_main *main, t_command *command, int type);
void					ft_get_pipe(t_main *main, t_command *command, int type);
int						ft_pwd(t_main *main, t_command *command);
void					write_to_args(char *arg, char **args, int *i);
void                    join_args(t_command *dst, char **args);

#endif
