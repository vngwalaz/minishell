/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:26:09 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/09/08 17:09:32 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	comand1(char **args)
{
    extern char **environ;
    int			pid;
    int			child_stat;

    pid = fork();
    if (pid == 0)
        execve(args[0], args, environ);
    else if (pid < 0)
        ft_putstr("Error\n");
    else
    {
        waitpid(pid, &child_stat, WUNTRACED);
        while (!WIFEXITED(child_stat) && !WIFSIGNALED(child_stat))
            waitpid(pid, &child_stat, WUNTRACED);
    }
}

void	comand2(char **args)
{
    extern char **environ;
    int			pid;
    int			child_stat;

    pid = fork();
    if (pid == 0)
        execve("/bin/ls", args, environ);
    else if (pid < 0)
        ft_putstr("error forking new process\n");
    else
    {
        waitpid(pid, &child_stat, WUNTRACED);
        while (!WIFEXITED(child_stat) && !WIFSIGNALED(child_stat))
            waitpid(pid, &child_stat, WUNTRACED);
    }
}

void	comand3(char **args)
{
    extern char **environ;
    int			pid;
    int			child_stat;

    pid = fork();
    if (pid == 0)
        execve("/bin/pwd", args, environ);
    else if (pid < 0)
        ft_putstr("error forking new process\n");
    else
    {
        waitpid(pid, &child_stat, WUNTRACED);
        while (!WIFEXITED(child_stat) && !WIFSIGNALED(child_stat))
            waitpid(pid, &child_stat, WUNTRACED);
    }
}

void	comand4(int_list *e)
{
    extern char **environ;
    int			pid;
    int			child_stat;

    pid = fork();
    if (pid == 0)
        execve("/bin/cd/flags", &e->oldpwd, environ);
    else if (pid < 0)
        ft_putstr("error forking new process\n");
    else
    {
        waitpid(pid, &child_stat, WUNTRACED);
        while (!WIFEXITED(child_stat) && !WIFSIGNALED(child_stat))
            waitpid(pid, &child_stat, WUNTRACED);
    }
}