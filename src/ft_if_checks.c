/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:17:53 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/09/08 17:51:19 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **args)
{
    int count;
    int len;

    count = 1;
    len = 0;
    while (args[count])
    {
        len = 0;
        while (args[count][len])
        {
            if(args[count][len] != '"' && args[count][len] != '\'')
                ft_putchar(args[count][len]);
            len++;
        }
        ft_putchar(' ');
        count++;
    }
    ft_putchar('\n');
}

void    ft_echo2(char **args)
{
    int count;
    int len;

    count = 2;
    len = 0;
    while (args[count])
    {
        len = 0;
        while (args[count][len])
        {
            if (args[count][len] != '"' || args[count][len] != '\'')
            ft_putchar(args[count][len]);
            len++;
        }
        count++;
        ft_putchar(' ');
    }
}

int		ft_export(int len, char **args)
{
    int			i;
    char		*temp;
    int			result2;

    i = -1;
    result2 = 0;
    while (i < len -1)
    {
        temp = ft_strchr(args[i], '=');
        len = ft_strlen(args[i]) - ft_strlen(temp);
        if (exec_command_setenv(args))
            result2 = -1;
        i++;
    }
    return (result2);
}