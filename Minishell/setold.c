#include "minishell.h"

void	setold(char ***envp)
{
	t_read	r;
	char	**tmp;
	int		i;
	char	**nwenv;
	
	nwenv = *envp;
	r.getp = NULL;
	tmp = NULL;
	i = 0;
	while (nwenv[i])
	{
		tmp = ft_strsplit(nwenv[i], '=');
		if (ft_strcmp(tmp[0] , "OLDPWD") == 0)
		{
			nwenv[i] = ft_strdup("OLDPWD=");
			nwenv[i] = ft_strjoin(nwenv[i], getcwd(r.getp, 255));
			ft_putendl(*nwenv);
			ft_freetab(tmp);
			break;
		}
		i++;
	}

}
