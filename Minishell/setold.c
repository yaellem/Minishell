#include "minishell.h"

void	setold(char ***envp)
{
	t_read	r;
	t_env	e;
	char	*str;
	int		i;
	
	e.nwenv = *envp;
	r.getp = NULL;
	i = 0;
	while (e.nwenv[i])
	{
		e.tmp = ft_strsplit(e.nwenv[i], '=');
		if ((ft_strcmp(e.tmp[0] , "OLDPWD")) == 0)
		{
			free(e.nwenv[i]);
			e.nwenv[i] = ft_strdup("OLDPWD=");
			str = getcwd(r.getp, 255);
			e.nwenv[i] = ft_strjoin(e.nwenv[i], str);
			ft_freetab(e.tmp);
			free(str);
			break;
		}
		i++;
		ft_freetab(e.tmp);
	}
}
