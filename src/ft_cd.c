/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 10:43:47 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/10/01 10:43:53 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_command_cd(char **args)
{
	char	*home;

	home = ft_getenv("$HOME");
	if (args[1] && args[2])
		ft_putstr("cd : too many arguments");
	else if (!args[1])
	{
		exec_cd(home, 0);
		return (1);
	}
	else
		exec_cd(args[1], 0);
	return (1);
}

void	exec_cd(char *args, int old_pwd_bool)
{
	char	*curr_dir;
	char	buff[BUFF_SIZE];
	char	*oldpwd;

	oldpwd = getenv("$OLDPWD");
	curr_dir = getcwd(buff, BUFF_SIZE);
	set_env("OLDPWD", curr_dir);
	if (!chdir(args))
	{
		if (old_pwd_bool)
			ft_putendl(oldpwd);
	}
	else
	{
		ft_putstr("cd :");
		if (access(args, F_OK))
			ft_putstr(" no such file or directory: ");
		else if (access(args, R_OK))
			ft_putstr(" permission denied: ");
		else
			ft_putstr(" not a directory");
		ft_putstr(args);
		ft_putchar('\n');
	}
}
