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
	char 			tmp[255];
	struct dirent 	*file;

}				t_read;

 int	ch_dir(const char *str);
void	ft_freetab(char **s1);
void	pwd(char **nwav);

 #endif