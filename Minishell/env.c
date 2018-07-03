#include "minishell.h"

char	**envrmt(char **envp)
{
	char	**nwenv;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	nwenv = malloc(sizeof(char*) * i + 1);
	i = 0;
	while (envp[i])
	{
		nwenv[i] = ft_strdup(envp[i]);
		i++;
	}
	nwenv = NULL;
	return (nwenv);
}