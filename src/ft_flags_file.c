/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 12:30:57 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/09/08 13:25:14 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_isprint_str(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			i++;
	}
	if (i == len)
		return (1);
	else
		return (0);
}

int			env_overwrite_pos(char *str)
{
	int		i;
	char	*temp;

	i = -1;
	while (g_env[++i])
	{
		temp = ft_strjoin(str, "=");
		if (!ft_strncmp(g_env[i], temp, ft_strlen(temp)))
		{
			free(temp);
			return (i);
		}
		free(temp);
	}
	return (i);
}

char		**realloc_env(int new_size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size));
	i = -1;
	while (g_env[++i] && i < new_size)
	{
		new[i] = ft_strdup(g_env[i]);
		free(g_env[i]);
	}
	free(g_env);
	return (new);
}

void		set_env(char *key, char *value)
{
	int		pos;
	char	*temp;

	pos = env_overwrite_pos(key);
	temp = ft_strjoin("=", value);
	if (g_env[pos])
	{
		free(g_env[pos]);
		if (value)
			g_env[pos] = ft_strjoin(key, temp);
		else
			g_env[pos] = ft_strjoin(key, "=");
	}
	else
	{
		g_env = realloc_env(pos + 1);
		if (value)
			g_env[pos] = ft_strjoin(key, temp);
		else
			g_env[pos] = ft_strjoin(key, "=");
	}
	free(temp);
}

int			exec_command_setenv(char **s_env_str)
{
	if (!s_env_str[1] || !s_env_str[2] || !ft_isprint_str(s_env_str[1]) // Syntax Cheking.
	|| ft_strcmp(s_env_str[2], "=") || !ft_isprint_str(s_env_str[3]))
	{
        ft_putstr("\x1b[1;91m");
		ft_putendl("ERROR");
		return (1);
	}
	set_env(s_env_str[1], s_env_str[3]);
	return (1);
}

void    ft_display_env(void)
{
    int i;

    i = -1;
    while (g_env[++i])
        ft_putendl(g_env[i]);
}

char	*ft_enviroment(char *str)
{
    int     i;
    char    *temp;

    i = -1;
    while (g_env[++i])
    {
        temp = ft_strjoin(str + 1, "=");
        if (!strncmp(g_env[i], temp, ft_strlen(temp)))
        {
            free(temp);
            return(ft_strchr(g_env[i], '=') + 1);
        }
    }
    return (NULL);
}

int		ft_unset(int len, char **args)
{
    extern char	**environ;
    char		**temp;
    int_list	 	ints;

    ints.count = 0;
    ints.result = -1;
    while (++ints.count < len -1)
    {
        ints.j = -1;
        if (args[ints.count][0] == '\0' || args[ints.count] == NULL || ft_strchr(args[ints.count], '=') != NULL)
            continue;
        temp = environ;
        ints.len = ft_strlen(args[ints.i]);
        while (temp[++ints.j] != NULL)
        {
            if (ft_strncmp(args[ints.count], temp[ints.j], ints.len) == 0 && temp[ints.j][ints.len] == '=')
            {
                ints.result = 0;
                ints.l = ints.j -1;
                while (temp[++ints.l + 1])
                    temp[ints.l] = temp[ints.l + 1];
            }
        }
    }
    return (ints.result);
}
