#include "minishell.h"

int		ch_dir(const char *str, char **envp)
{
	t_read r;
	char	**tmp;
	char	**nwav;
	int i;

	i = 0;
	tmp = NULL;
	r.getp = NULL;
	if (!str || ft_strcmp(str, "~") == 0) 
		str = tilde(envp);
//		ft_putendl("MDR");
	while (envp[i])
	{
		tmp = ft_strsplit(envp[i], '=');
		if (ft_strcmp(tmp[0] , "OLDPWD") == 0)
		{
			*envp = ft_strdup("OLDPWD=");
			*envp = ft_strjoinnf(envp[i], getcwd(r.getp, 255));
			ft_putendl(*envp);	
			ft_freetab(tmp);
			break;
		}
		i++;
	}
	if (str && ft_strcmp(str, "-") == 0)
	{
		ft_putendl(tiret(envp));
		ft_putendl(envp[i]);	
		str = tiret(envp);
	}
	else if (str && str[0] == '~')
	{
		if (str[1] == '-' && !str[2])
			str = tiret(envp);
		else
		{
			i = 1;
			tmp = ft_strsplit(str, '/');
			free(tmp[0]);
			tmp[0] = ft_strdup(tilde(envp));
			str = ft_strdup(tmp[0]);
			while (tmp[i])
			{
				str = ft_strjoinnf(str, "/");
				str = ft_strjoinnf(str, tmp[i]);
				i++;
			}
		}
	}
		r.ptr = opendir(str);
		if (r.ptr == NULL && lstat(str, &r.buf) == 0)
		{
			ft_putstr("ch_dir: not a directory: ");
			ft_putendl(str);
			return (0);
		}
		lstat(str, &r.buf);
		if (!S_ISDIR(r.buf.st_mode))
		{
		
			ft_putstr("ch_dir: no such file or directory: ");
			ft_putendl(str);
			return (0);
		}			
		chdir(str);
		i = 0;
		while (envp[i])
	{
		tmp = ft_strsplit(envp[i], '=');
		if (ft_strcmp(tmp[0] , "PWD") == 0)
		{
			envp[i] = ft_strdup("PWD=");
			envp[i] = ft_strjoinnf(envp[i], getcwd(r.getp, 255));
			ft_freetab(tmp);
			break;
		}
		i++;
	}
	return (1);

}
