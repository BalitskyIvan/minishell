/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:53:52 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/06 19:53:56 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_commands(t_command *command, char *dsc)
{
	int i;
	int i2;
	
	i = 0;
	while (command)
	{
		// if (command->undefined_arg)
		// {
		// 	ft_putstr_fd("\033[0;31m", 0);
		// 	ft_putstr_fd(BOLD, 0);
		// 	ft_putstr_fd("Ублюдок мать твою а ну иди сюда говно собачье а ну решил ко мне лезть\nты засранец вонючий мать твою а ну иди сюда попробуй меня\nтрахнуть я тебя сам трахну ублюдок онанист чертов будь ты \nпроклят иди идиот трахать тебя и всю твою семью говно\nсобачье жлоб вонючий дерьмо сука падла иди сюда\nмерзавец негодяй гад иди сюда ты говно жопа\n", 0);
		// 	ft_putstr_fd(RESET, 0);
		// 	command = command->next;
		// }
		//else{
		ft_putstr_fd(dsc, 0);
		ft_putstr_fd("command no: ", 0);
		ft_putnbr_fd(i, 0);
		ft_putstr_fd("\n", 0);
		ft_putstr_fd("command is: ", 0);
		ft_putstr_fd(command->command_str, 0);
		ft_putstr_fd("\n", 0);
		i2 = 0;
		while (command->args[i2])
		{
			ft_putstr_fd("       arg: ", 0);
			ft_putstr_fd(command->args[i2], 0);
			ft_putstr_fd("\n", 0);
			i2++;
		}
		ft_putstr_fd("\n", 0);
		if (command->pipe)
			print_commands(command->pipe, "PIPE");
		if (command->redirect)
			print_commands(command->redirect, "REDIRECT");
		if (command->back_redirect)
			print_commands(command->back_redirect, "BACK_REDIRECT");
		if (command->double_redirect)
			print_commands(command->double_redirect, "DOUBLE_REDIRECT");
		command = command->next;
		//}
	}
}
