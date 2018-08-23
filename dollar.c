#include "minishell.h"

char	*trim(char *str)
{
	char *dst;
	int	 i;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] && (str[i] != '/' && str[i] != '$' && str[i] != ','))
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*dollar(char *str, char **env)
{
	int		i;
	int		x;
	int		y;
	int z;
	char	**tmp;
	char	*temp;
	char	*dst;
	char	*strim;
	char	*test;

	i = -1;
	x = 0;
	y = 0;
	z = 0;
	temp = NULL;
	dst = NULL;
	while (str[++i])
	{
		if (str[i] == '$')
			x = 1;
	}
	if (x == 0 || ft_strcmp(str, "$") == 0)
		return (str);
	x = -1;
	i = -1;
	/*while (env[++i])
	{
		tmp = ft_strsplit(env[i], '=');*/
		while (str && str[++x])
		{
			if (str[x] == '$')
			{
				z = 1;
				test = strim;
				strim = trim(&str[x + 1]);
				if (!str[x+1])
					y =1;
				while (env[++i])
				{
					tmp = ft_strsplit(env[i], '=');
					if (ft_strcmp(tmp[0], strim) == 0 )
					{
						temp = ft_strdup(&str[x + ft_strlen(tmp[0])]);
						y == 0 ? dst = ft_strndup(str, '$') : 0;
						y = 1;
						dst = ft_strjoin(dst, tmp[1]);
						//ft_putendl(&temp[1]);
						if ((temp[1] == '/' || (temp[1] == '$' && (temp[2] == '/'
						||temp[2] == ',' || !temp[2])) 
						|| temp[1] == ',')) 
						{
							//if (temp[1] == '$' && temp[2] == '/)
								dst = ft_strjoin(dst, &temp[1]);
							//if ((temp = ft_strchr(str, '/')) && temp[1] != '$')
							//	dst = ft_strjoin(dst, ft_strchr(str, '/'));
							//else 
							//	dst = ft_strjoin(dst, "/");
						}
					//	free(temp);
					}
					ft_freetab(tmp);
				}	
				if (y == 0)
				{	
					y == 0 ? dst = ft_strndup(str, '$') : 0;
					dst = ft_strjoin(dst, ft_strinddup(str, '$'));
					y = 1;
				}
				free(strim);	
			}
			i = -1;
	}
	y == 0 ? ft_putendl("The variable does not exist") : 0;
	return (dst ? dst : str);
}
