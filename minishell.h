/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 02:52:07 by ymarcill          #+#    #+#             */
/*   Updated: 2018/09/12 19:58:22 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>
# define TEXT_COLOR_CYAN "\x1b[36m"
# define TEXT_COLOR_GREEN "\x1b[32m"
# define TEXT_COLOR_RED "\x1b[31m"
# define TEXT_COLOR_RESET "\x1b[0m"

typedef struct	s_read
{
	DIR				*ptr;
	struct stat		buf;
	char			*getp;
	char			**getl;
	char			tmp[255];
	char			*path;
	char			*temp;
	char			*dst;
	struct dirent	*file;

}				t_read;

typedef	struct	s_env
{
	char	**tmp;
	char	**nwenv;
	char	***nwav;
	char	*str;
	char	*freem;
	char	*line;
	char	*dst;
	char	*temp;
	char	*strim;
	char	**envcopy;
}				t_env;

typedef struct	s_index
{
	int		i;
	int		y;
	int		x;
	int		z;
	int		check;
	int		test;
	int		opt;
	int		j;
	char	*tmp;
	pid_t	father;
}				t_index;

char			*if_dollar(char *str, char **envp, char *dst, int x);
char			*is_good_end(char *temp, char *dst, char *tmp);
char			*if_not_var(char *strim, char *str, char *dst, int x);
char			*iscequal(char *str);
char			*check_occ_bis(char *envcopy, char *nwav, int *check);
char			**minishell_core(char **nwav, char **nwenv);
int				is_char(char *str, char c);
int				ft_tablen(char **tab);
char			*trim(char *str);
void			minishell(char *line, char **nwenv);
char			**envrmt(char **envp);
char			***virgule_point(char *line);
char			*dollar(char *string, char **env);
char			**get_line(char **env);
char			*getpath(char **nwav, char **path);
int				builtin_gestion(char **nwav, char ***env);
int				binary_gestion(char **nwav, char **nwenv, char *str);
void			myecho(char **nwav, char **env);
int				ch_dir(char *str, char ***envp);
char			*change_dir_special(char *str, char **envp);
char			*tilde(char **envp);
char			*tiret(char **envp);
void			setold(char ***envp);
void			setpwd(char ***envp);
char			**set_env(char **nwav, char ***env, char *str);
char			**unset_env(char **name, char ***env);
char			**envi(char ***envp, char **nwav);
void			pwd(char **nwav);
void			pwd_bis();
int				ft_is_here(char *str, char c);
void			ft_freetab(char **s1);
void			ft_freetrtab(char ***s1);
void			print_tab_a(char **str);
char			**ft_strsplitq(char const *s, char c);
char			*ft_strdupn(char *str, char c);
char			*ft_strldup(char *str, char c);
char			*ft_strinddup(char *str, char c);

#endif
