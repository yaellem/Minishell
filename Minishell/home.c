#include "minishell.h"

char	*tilde(char **envp)
{
	int		i;
	char	*tilde;
	char	**tmp;

	i = 0;
	tilde = NULL;
	while (envp[i])
	{
		tmp = ft_strsplit(envp[i], '=');
		if (ft_strcmp(tmp[0], "HOME") == 0)
		{
			tilde ? free(tilde) : 0;
			tilde = ft_strdup(tmp[1]);
			ft_freetab(tmp);
			break;
		}
		ft_freetab(tmp);
		i++;
	}
	return (tilde);
}

char	*tiret(char **envp)
{
	int		i;
	char	*tiret;
	char	**tmp;

	i = 0;
	tiret = NULL;
	while (envp[i])
	{
		tmp = ft_strsplit(envp[i], '=');
		if (ft_strcmp(tmp[0], "OLDPWD") == 0)
		{
			tiret = ft_strdup(tmp[1]);
			break;
		}
		ft_freetab(tmp);
		i++;
	}
	return (tiret);

}
