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
//# define ~ $HOME

typedef struct  s_read
{
	DIR				*ptr;
	struct stat 	buf;
	char			*getp;
	char 			tmp[255];
	struct dirent 	*file;

}				t_read;

int		ch_dir(const char *str, char **envp);
void	ft_freetab(char **s1);
void	pwd(char **nwav);
void	print_tab_a(char **str);
char	**envrmt(char **envp);
char	*tilde(char **envp);
char	*tiret(char **envp);

#endif
