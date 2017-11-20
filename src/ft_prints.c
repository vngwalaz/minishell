/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:17:23 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/09/01 12:14:51 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_newline(const char *str)
{
    ft_putstr(str);
    ft_putchar('\n');
}

int			ft_isemptystr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			return (0);
	}
	return (1);
}

void		work_dir(void)
{
	char 	*dir;
	char 	buff[BUFF_SIZE];
	dir = getcwd(buff, BUFF_SIZE);
    dir = ft_strrchr(dir, '/');
    ft_putstr("\x1b[38;5;10m");
    ft_putstr("$> ");
    ft_putstr("\033[0;94m");
    ft_putstr(dir + 1);
    ft_putstr("\x1b[31m -> ");
    ft_putstr("\x1b[0;37m");
}

void	ft_exit(void)
{
	ft_putstr("\x1b[0;93m");
	ft_putstr("GOODBYE 👍\n");
	exit(EXIT_SUCCESS);
}