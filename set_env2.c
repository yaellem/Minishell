#include "minishell.h"

char    **set_env(char **nwav, char ***env)
{
	t_env   e;
	char    **envcopy;
	int     i;
	int     j;
	int		x;
	int		check;
	char	*tmp;

	j = 0;
	x = 0;
	envcopy = NULL;
	e.nwenv = *env;
	check = 0;
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
				tmp = ft_strndup(nwav[j], '=');
				if (ft_strcmp(e.tmp[0], tmp) == 0)
				{
					x = 1;
					free(e.nwenv[i]);
					e.nwenv[i] = ft_strndup(nwav[j], '=');
					e.nwenv[i] = ft_strjoin(e.nwenv[i], ft_strchr(nwav[j], '='));
				}
				free(tmp);
				ft_freetab(e.tmp);
			}
		}
	}
	if (!(envcopy = malloc(sizeof(char *) * (i + j + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (e.nwenv[++i])
		envcopy[i] = ft_strdup(e.nwenv[i]);
	envcopy[i] = NULL;
	while (nwav[++j])
	{
		x = i;
		i = 0;
		while (envcopy[i])
		{
			e.tmp = ft_strsplit(envcopy[i], '=');
			tmp = ft_strndup(nwav[j], '=');
			if (ft_strcmp(e.tmp[0], tmp) == 0)
			{
				free(envcopy[i]);
				envcopy[i] = tmp;
				envcopy[i] = ft_strjoin(envcopy[i], ft_strchr(nwav[j], '='));
				check = 1;
			}
			check == 1 ? 0 : free(tmp);
			ft_freetab(e.tmp);
			i++;
		}
		if (check == 0)
		{
			envcopy[i] = ft_strdup(nwav[j]);
			envcopy[i + 1] = NULL;
		}
		i = x;
		i++;
		check = 0;
	}
	envcopy[i] = NULL;
	ft_freetab(*env);
	return (envcopy);
}

