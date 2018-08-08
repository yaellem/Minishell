#include "minishell.h"


int    ft_no_access(const char *str)
{
	ft_putstr("cd: ");
	ft_putstr(str);
	ft_putendl(": Permission denied");
	return (0);
}

int		ch_dir(char *str, char ***envp)
{
	t_read r;
	char	*dst;

	dst = NULL;
	dst = change_dir_special((char*)str, *envp);
	r.ptr = opendir(dst);
	if (r.ptr == NULL && lstat(dst, &r.buf) == 0)
	{
		ft_putstr("ch_dir: not a directory: ");
		ft_putendl(dst);
		return (0);
	}
	if (stat(dst, &r.buf) == -1 || !S_ISDIR(r.buf.st_mode))
	{
		ft_putstr("ch_dir: no such file or directory: ");
		ft_putendl(dst);
		r.ptr ? closedir(r.ptr) : 0;
		return (0);
	}
	if (!(r.buf.st_mode & S_IXUSR))
		return (ft_no_access(dst));
	setold(envp);
	chdir(dst);
	setpwd(envp);
	r.ptr ? closedir(r.ptr) : 0;
	free(dst);
	dst = NULL;
	return (1);
}
