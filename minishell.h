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

typedef struct  s_read
{
	DIR				*ptr;
	struct stat 	buf;
	char			*getp;
	char 			tmp[255];
	struct dirent 	*file;

}				t_read;

typedef	struct	s_env
{
	char	**tmp;
	char	**nwenv;
	char	***nwav;
	char	*str;
	char	*line;
}				t_env;

typedef struct s_index
{
	int i;
	int y;
	int x;
}				t_index;

void	minishell(char *line, char **nwenv);
char	**envrmt(char **envp);
char	***virgule_point(char *line);
char	*dollar(char *str, char **env);
char	**get_line(char **env);
char	*getpath(char **str, char **path);
int		builtin_gestion(char **nwav, char ***env);
int		binary_gestion(char **nwav, char **nwenv, char *str);
void	myecho(char **nwav);
int		ch_dir(char *str, char ***envp);
char	*change_dir_special(char *str, char **envp);
char	*tilde(char **envp);
char	*tiret(char **envp);
void	setold(char ***envp);
void	setpwd(char ***envp);
char	**set_env(char **nwav, char ***env);
char	**unset_env(char **name, char ***env);
char	**envi(char ***envp, char **nwav);
void	pwd(char **nwav);
int		ft_is_here(char *str, char c);
void	ft_freetab(char **s1);
void	ft_freetrtab(char ***s1);
void	print_tab_a(char **str);
char	**ft_strsplitq(char const *s, char c);

#endif
