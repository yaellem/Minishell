#include "minishell.h"

void    setpwd(char ***envp)
{
	t_read  r;
	t_env   e;
	int     i;

	e.nwenv = *envp;
	r.getp = NULL;
	i = 0;
	while (e.nwenv[i])
	{
		e.tmp = ft_strsplit(e.nwenv[i], '=');
		if ((ft_strcmp(e.tmp[0] , "PWD")) == 0)
		{
			e.nwenv[i] = ft_strdup("PWD=");
			e.nwenv[i] = ft_strjoin(e.nwenv[i], getcwd(r.getp, 255));
			ft_freetab(e.tmp);
			break;
		}
		i++;
	}
}

