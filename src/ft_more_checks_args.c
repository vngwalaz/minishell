#include "minishell.h"

void	ft_check_more_args(char **args)
{
    int_list e;

    if (args[0] != '\0')
    {
        if (ft_strcmp(args[0], "echo") == 0)
        {
            if (ft_strcmp(args[1], "-n") == 0)
                ft_echo2(args);
            else if (args[1][0]  == '$')
                ft_putendl(ft_enviroment(args[1]));
            else 
                ft_echo(args);
        }
        else if (ft_strcmp(args[0], "cd") == 0 && e.cd_dash == 0)
        {
            if (ft_strcmp(&args[0][1], "~/") == 0)
            {
                e.oldpwd = getenv("PWD");
                exec_command_cd(args);
            }
            else
            {
                e.oldpwd = getenv("PWD");
                exec_command_cd(args);
            }
        }
        else if (ft_strcmp(args[0], "cd") == 0 && e.cd_dash == 1)
        {
            e.oldpwd = getenv("PWD");
            ft_putstr(e.oldpwd);
            ft_putchar('\n');
            chdir(e.oldpwd);
        }
        else
            ft_external(args);
    }
}

void	ft_bin_pwd(char **args)
{
	ft_putstr("\x1b[0;94m");
	ft_putstr("Path Folder Updated ♻️\n");
    ft_putstr("\x1b[0;37m");
    comand3(args);
}