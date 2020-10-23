/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklotz <mklotz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:56:54 by lmallado          #+#    #+#             */
/*   Updated: 2020/10/23 12:20:20 by mklotz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void fill_already_print(int **alr_ex, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        (*alr_ex)[i] = -1;
        i++;
    }
}

static int  is_already_exist(int **already_exist, int number, int  size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if ((*already_exist)[i] == number)
            return (1);
        i++;
    }
    return (0);
}

static char *get_next_str(int **already_exist, char **env, int size)
{
    int min_val_index;
    int i;

    i = 0;
    min_val_index = -1;
    while (i < size)
    {
        if (!is_already_exist(already_exist, i, size))
        {
            if (min_val_index == -1)
                min_val_index = i;
            else
            {
                if (ft_strncmp(env[min_val_index], env[i], ft_strlen(env[min_val_index])) >= 0)
                    min_val_index = i;
            }
        }
        i++;
    }
    i = 0;
    while (i < size)
    {
        if ((*already_exist)[i] == -1)
        {
            (*already_exist)[i] = min_val_index;
            break;
        }
        i++;
    }
    return (env[min_val_index]);
}

static void print_result(t_main *main, int **already_exist, int size)
{
    int i2;
    char *str;
    int  val_printed;

    i2 = 0;
    val_printed = 0;
    str = get_next_str(already_exist, main->env, size);
    ft_putstr_fd("declare -x ", 1);
    while (str[i2])
    {
        if (i2 != 0 && str[i2 - 1] == '=')
        {
            val_printed = 1;
            ft_putchar_fd('"', 1);
        }
        ft_putchar_fd(str[i2], 1);
        i2++;
    }
    if (i2 != 0 && val_printed)
        ft_putchar_fd('"', 1);
    ft_putstr_fd("\n", 1);
}

void print_export(t_main *main)
{
    int i;
    int *already_print;
    int size;

    i = 0;
    size = get_sizeof_args(main->env);
    already_print = (int*)malloc(size * sizeof(int));
    fill_already_print(&already_print, size);
    while (i < size)
    {
        print_result(main, &already_print, size);
        i++;
    }
    free(already_print);
}