#include "minishell.h"

void	pwd(char **nwav)
{
	char	*buf;
	char	*str;

	buf = NULL;
	str = NULL;
	if (nwav[1])
		ft_putendl("pwd: Too many arguments");
	else
	{
		str = (getcwd(buf, 255));
		ft_putendl(str);
	}
	free(str);
}
