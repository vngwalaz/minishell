/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:18:05 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/09/08 16:42:56 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_environ(void)
{
	extern char **environ;
	int i;

	i = -1;	
	while (environ[++i])
		i++;
	g_env = (char **)malloc(sizeof(char *) * (i + 1));
	g_env[i] = NULL;
	i = -1;
	while (environ[++i])
		g_env[i] = ft_strdup(environ[i]);
}

int ft_strmatch(char *s1, char c)
{
	int i;

	i = -1;
	while (s1[++i] != '\0')
	{
		if (s1[i] == c)
		return (1);
	}
	return (0);
}

int		main(void)
{
	char buffer[BUFF_SIZE + 1];
	char **args;
	int_list e;

	
	init_environ(); 
	while (1)
	{
		work_dir();
		e.cd_dash = 0;
		ft_bzero(buffer, BUFF_SIZE + 1);
		read(0, &buffer, BUFF_SIZE);
		if (ft_strmatch(buffer, '-') == 1)
			e.cd_dash = 1;
		args = ft_strsplit(ft_strtrim(buffer), ' ');
		if (*args != NULL)
			ft_check_args(&args[0], &e);
		else
			comand1(args);
	}
	return(0);
}