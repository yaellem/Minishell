#include "minishell.h"

char	**envi(char **envp, char**nwav)
{
	int		i;
	int		x;
	char	**tmp;

	i = 0;
	x = 0;
	if (!nwav[1] && envp)
		print_tab_a(envp);
	else
	{
		if (nwav && !nwav[2])
			ft_putendl("Not enough arguments");
		else
		{
			while (envp && envp[i])
			{
				tmp = ft_strsplit(envp[i], '=');
				if (ft_strcmp(tmp[0], nwav[1]) == 0)
				{
					x = 1;
					free(envp[i]);
					envp[i] = ft_strdup(nwav[1]);
					envp[i] = ft_strjoin(envp[i], "=");
					envp[i] = ft_strjoin(envp[i], nwav[2]);
					break ;
				}
				i++;
			}
			if (x == 0)
			{
				ft_putstr("The variable \"");
				ft_putstr(nwav[1]);
				ft_putendl("\" does not exist");
			}
		}
	}
	return (envp);
}
