#include "minishell.h"

void	pwd(char **nwav)
{
	char	*buf;

	buf = NULL;
	if (nwav[1])
		ft_putendl("pwd: Too many arguments");
	else
		ft_putendl(getcwd(buf, 255));
}