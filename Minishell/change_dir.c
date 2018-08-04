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

//	str ? free(str) : 0;
	str = change_dir_special((char*)str, *envp);
	r.ptr = opendir(str);
//	printf("%p\n", r.ptr);
//	printf("%d\n", lstat(str, &r.buf));
//	printf("%d\n", stat(str, &r.buf));
	if (r.ptr == NULL && lstat(str, &r.buf) == 0)
	{
		ft_putstr("ch_dir: not a directory: ");
		ft_putendl(str);
		return (0);
	}
//	stat(str, &r.buf);
//	perror("");
//	printf("%d\n", S_ISDIR(r.buf.st_mode));
	if (stat(str, &r.buf) == -1 || !S_ISDIR(r.buf.st_mode))
	{
		ft_putstr("ch_dir: no such file or directory: ");
		ft_putendl(str);
		r.ptr ? closedir(r.ptr) : 0;
		return (0);
	}
	if (!(r.buf.st_mode & S_IXUSR))
		return (ft_no_access(str));
	//free(str);
	setold(envp);
	chdir(str);
	setpwd(envp);
	r.ptr ? closedir(r.ptr) : 0;
//	free(str);
//	str = NULL;
	return (1);
}
