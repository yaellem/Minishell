#include "minishell.h"

char	*dollar(char *str, char **env)
{
	int		i;
	int		x;
	char	**tmp;

	i = 0;
	x = 0;
	if (str[0] != '$')
		return (str);
	while (env[i])
	{
		tmp = ft_strsplit(env[i], '=');
		if (ft_strcmp(tmp[0], &str[1]) == 0)
		{
			free(str);
			str = ft_strdup(tmp[1]);
			break ;
		}
		i++;
	}
	return (str);	
}
