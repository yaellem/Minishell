#include "minishell.h"

char	**envrmt(char **envp)
{
	char	**nwenv;
	char	**tmp;
	int		i;
	int		x;

	i = 0;
	while (envp[i])
		i++;
	nwenv = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (envp[i])
	{
		tmp = ft_strsplit(envp[i], '=');
		if (ft_strcmp(tmp[0], "SHLVL") == 0)
		{
			x = ft_atoi(tmp[1]) + 1;
			nwenv[i] = ft_strjoinnf("SHLVL=", ft_itoa(x));
		}
		else
			nwenv[i] = ft_strdup(envp[i]);
		i++;
	}
	nwenv[i] = NULL;
	return (nwenv);
}
