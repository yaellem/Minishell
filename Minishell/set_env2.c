#include "minishell.h"

char    **set_env(char **nwav, char ***env)
{
	t_env   e;
	char    **envcopy;
	int     i;
	int     j;
	int		x;

	j = 0;
	x = 0;
	envcopy = NULL;
	e.nwenv = *env;
	if (!nwav[1])
	{
		ft_putendl("Not enough arguments");
		return (NULL);
	}
	while (nwav[++j])
	{
		if (ft_strchr(nwav[j], '=') == 0)
		{
			ft_putstr(nwav[j]);
			ft_putendl(": There is not the character \'=\'");
			return (NULL);
		}
		else
		{
			i = -1;
			while (e.nwenv[++i])
			{
				e.tmp = ft_strsplit(e.nwenv[i], '=');
				if (ft_strcmp(e.tmp[0], ft_strndup(nwav[j], '=')) == 0)
				{
					x = 1;
					free(e.nwenv[i]);
					e.nwenv[i] = ft_strndup(nwav[j], '=');
					e.nwenv[i] = ft_strjoin(e.nwenv[i], ft_strchr(nwav[j], '='));
				}
			}
		}
	}
	if (x == 0)
	{
		if (!(envcopy = malloc(sizeof(char *) * (i + j + 1))))
			return (NULL);
		i = 0;
		j = 0;
		while (e.nwenv[i])
		{
			envcopy[i] = ft_strdup(e.nwenv[i]);
			i++;
		}
		while (nwav[++j])
		{
			envcopy[i] = ft_strdup(nwav[j]);
			i++;
		}
		envcopy[i] = NULL;
		return (envcopy);
	}
	return (NULL);
}

