/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vngwalaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:17:33 by vngwalaz          #+#    #+#             */
/*   Updated: 2017/09/08 17:51:37 by vngwalaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define BUFF_SIZE 1024

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <ctype.h>
# include <sys/wait.h>
# include <locale.h>
# include <stdlib.h>


typedef struct	int_list
{
	int			k;
	int			i;
	int			count;
	int			j;
	int			l;
	int			result;
	int			len;
	int			cd_dash;
	char		*oldpwd;
}				int_list;

/* global vars*/
char 	**g_env;
pid_t   g_pid;

int		main(void);
void	ft_check_args(char **args, int_list *e);
void	ft_if_checks(char **args);
void	ft_echo(char **args);
int     ft_unset(int len, char **args);
int     ft_export(int len, char **args);
int     ft_set_enviroment(char *args);
char    *ft_enviroment(char *str);
void    ft_display_env(void);
int		exec_command_setenv(char **s_env_str);
void    ft_external(char **args);
void	ft_newline(const char *str);
void	comand2(char **args);
void	ft_echo2(char **args);
void	comand1(char **args);
void	comand3(char **args);

/*    ft_cd shandis   */
int		ft_cd(char **args);
void	exec_cd(char *args, int old_pwd_bool);
int		exec_command_cd(char **args);
void	set_env(char *key, char *value);

char	*ft_getenv(char *s_envstr);

/*     extra function    */
int		ft_strstartswith(char *s1, char *s2);
int		ft_isemptystr(char *str);
void	comand4(int_list *e);

/*     cool shandis     */
void	work_dir(void);

void	ft_exit(void);
void	ft_bin_pwd(char **args);
void	ft_check_more_args(char **args);
#endif