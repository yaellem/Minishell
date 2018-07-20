#include "minishell.h"

char	**get_line(char **env)
{
	char	**tmp;
	char	**path;
	int		i;

	i = 0;
	tmp = NULL;
	path = NULL;
	while (env[i])
	{
		tmp = ft_strsplit(env[i], '=');
		if ((ft_strcmp(tmp[0], "PATH")) == 0)
		{
			path = ft_strsplit(tmp[1], ':');
			break;
		}
		i++;
	}
	ft_freetab(tmp);
	return (path);
}

char	*getpath(char **str, char **path)
{
	int		i;
	t_read	r;
	char	*command;

	i = 0;
	while (path[i])
	{
		r.ptr = opendir(path[i]);
		while (r.ptr && (r.file = readdir(r.ptr)))
		{
			if ((ft_strcmp(r.file->d_name, str[0])) == 0)
			{
				command = ft_strjoinnf(path[i], "/");
				command = ft_strjoin(command, str[0]);
				break ;
			}
		}
		closedir(r.ptr);
		i++;
	}
	return (command);
}
