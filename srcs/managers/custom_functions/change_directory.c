/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:44:21 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/18 16:52:36 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int			get_sizeof_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void		update_pwd(t_main *main, int type)
{
	char		*pwd;
	char		*tmp;

	if (!(pwd = getcwd(NULL, 0)))
		return ;
	if (!get_env_value(main, (type == 0) ? "PWD" : "OLDPWD"))
	{
		free(pwd);
		return ;
	}
	unset_env(main, (type == 0) ? "PWD" : "OLDPWD");
	tmp = pwd;
	pwd = ft_strjoin((type == 0) ? "PWD=" : "OLDPWD=", pwd);
	export_env(main, pwd);
	free(tmp);
	free(pwd);
}

int			get_home_path(char *path, t_main *main)
{
	int		status;
	char	*temp;
	char	*temp2;
	char	*temp3;
	
	if (path == NULL || path[1] == '\0')
		temp = get_env_value(main, "HOME");
	else
	{
		temp = get_env_value(main, "HOME");
		temp2 = ft_substr(path, 1, -1);
		temp3 = ft_strjoin(temp, temp2);
		free(temp);
		temp = ft_strdup(temp3);
		free(temp3);
		free(temp2);
	}
	update_pwd(main, 1);
	status = chdir(temp);
	if (status == 0)
		update_pwd(main, 0);
	free(temp);
	return (status);
}

int			change_directory(t_command *command, t_main *main)
{
	int		status;

	if (command->args[1] == NULL || command->args[1][0] == '~')
		status = get_home_path(command->args[1], main);
	else
	{
		update_pwd(main, 1);
		status = chdir(command->args[1]);
		if (status == 0)
			update_pwd(main, 0);
	}
	if (status == -1)
		send_custom_error("Not a valid path");
	return (1);
}
