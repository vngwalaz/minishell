/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 10:44:03 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/10/01 10:44:06 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strstartswith(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char		*ft_getenv(char *s_envstr)
{
	int		i;
	char	*temp;

	i = -1;
	while (g_env[++i])
	{
		temp = ft_strjoin(s_envstr + 1, "=");
		if (ft_strstartswith(g_env[i], temp))
		{
			free(temp);
			return (ft_strchr(g_env[i], '=') + 1);
		}
		free(temp);
	}
	return (NULL);
}
