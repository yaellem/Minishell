#include "minishell.h"

void	pwd(char **nwav)
{
	char	*buf;
	char	*str;

	buf = NULL;
	str = NULL;
	if (nwav && nwav[1])
		ft_putendl("pwd: Too many arguments");
	else
	{
		str = (getcwd(buf, 255));
		ft_putendl(str);
	}
	free(str);
}

void	pwd_bis()
{
	char	*buf;
	char	*str;

	buf = NULL;
	str = (getcwd(buf, 255));
	ft_putstr(str);
	free(str);
}
