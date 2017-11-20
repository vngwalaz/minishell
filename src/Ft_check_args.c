/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:16:53 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/09/08 17:50:02 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_args(char **args, int_list *e)
{
    int len;

    len = 0;
    if (args[0] != '\0')
    {
        if (ft_strcmp(args[0], "echo") == 0)
            ft_check_more_args(args);
        else if (ft_strcmp(args[0], "cd") == 0 && e->cd_dash == 0)
                ft_check_more_args(args);
        else if (ft_strcmp(args[0], "cd") == 0 && e->cd_dash == 1)
        {
            e->oldpwd = getenv("PWD");
            ft_putstr(e->oldpwd);
            ft_putchar('\n');
            chdir(e->oldpwd);
        }       
        else if (ft_strcmp(args[0], "env") == 0)
            ft_display_env();
        else if (ft_strcmp(args[0], "export") == 0)
            ft_display_env();
        else if (ft_strcmp(args[0], "unset") == 0)
            ft_unset(len, args);
        else if (ft_strcmp(args[0], "ls") == 0)
            comand2(args);
        else if (strcmp(args[0], "setenv") == 0)
            exec_command_setenv(args);
        else if (ft_strcmp(args[0], "clear") == 0)
            ft_external(args);
        else if (ft_strcmp(args[0], "exit") == 0)
            ft_exit();
        else if (ft_strcmp(args[0], "/bin/ls") == 0)
            comand2(args);
        else if (ft_strcmp(args[0], "/bin/pwd") == 0)
            ft_bin_pwd(args);
        else
            ft_external(args);
    }
}

void    ft_external(char **args)
{
    extern char	**environ;
    pid_t		pid;
    int			status;
    char		*dest;
    char		*dest2;

    dest = ft_strjoin("/bin/", args[0]);
    dest2 = ft_strjoin("/usr/bin/", args[0]);
    pid = fork();
    if (pid == 0)
    {
        if (execve(dest, args, environ) == -1)
            if (execve(dest2, args, environ) == -1)
            {
                ft_putstr("\x1b[1;91m");
                ft_putstr("minishell: command not found: ");
                ft_putstr(args[0]);
                ft_putstr("\n");
            }
        free(dest);
        free(dest2);
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
        ft_puterror_fd("Unable to fork", STDERR);
    else
    {
        while ((pid = waitpid(0, &status, WNOHANG | WUNTRACED) > -1 ))
            waitpid(pid, &status, WUNTRACED);
    }
    free(dest);
    free(dest2);
}
