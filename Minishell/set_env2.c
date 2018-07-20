#include "minishell.h"

char    **set_env(char **nwav, char ***env)
{
	t_env   e;
	char    **envcopy;
	int     i;
	int     j;

	i = 0;
	j = 0;
	envcopy = NULL;
	e.nwenv = *env;
	if (!nwav[1] || !nwav[2])
	{
		ft_putendl("Not enough arguments");
		return (NULL);
	}
	if (nwav[3])
	{
		ft_putendl("Too many arguments");
		return (NULL);
	}
	while (e.nwenv[i])
	{
		e.tmp = ft_strsplit(e.nwenv[i], '=');
		if (ft_strcmp(e.tmp[0], nwav[1]) == 0)
		{
			j = 1;
			free(e.nwenv[i]);
			e.nwenv[i] = ft_strdup(nwav[1]);
			e.nwenv[i] = ft_strjoin(e.nwenv[i], "=");
			e.nwenv[i] = ft_strjoin(e.nwenv[i], nwav[2]);
			break ;
		}
		i++;
	}
	if (j == 0)
	{
		if (!(envcopy = malloc(sizeof(char *) * (i + 2))))
			return (NULL);
		i = 0;
		while (e.nwenv[i])
		{
			envcopy[i] = ft_strdup(e.nwenv[i]);
			i++;
		}
		envcopy[i] = ft_strdup(nwav[1]);
		envcopy[i] = ft_strjoin(envcopy[i], "=");
		envcopy[i] = ft_strjoin(envcopy[i], nwav[2]);
		envcopy[i + 1] = NULL;
		return (envcopy);
	}
	return (NULL);
}

