/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:15:34 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/20 18:15:38 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

void join_args(t_command *dst, char **args)
{
    char **copy;
    int  i;
    int  i2;

    i = 0;
    i2 = 1;
    copy = dst->args;
    dst->args = (char**)malloc((get_sizeof_args(dst->args) +
            get_sizeof_args(dst->args) + 1) * sizeof(char**));
    while (i < get_sizeof_args(copy))
    {
        dst->args[i] = ft_strdup(copy[i]);
        i++;
    }
    while (i2 < get_sizeof_args(args))
    {
        dst->args[i] = ft_strdup(args[i2]);
        i++;
        i2++;
    }
    dst->args[i] = NULL;
    free_args(copy);
}