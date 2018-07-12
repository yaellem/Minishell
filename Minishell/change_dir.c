#include "minishell.h"

int		ch_dir(const char *str, char ***envp)
{
	t_read r;

	str = change_dir_special((char*)str, *envp);
	setold(envp);
	r.ptr = opendir(str);
	if (r.ptr == NULL && lstat(str, &r.buf) == 0)
	{
		ft_putstr("ch_dir: not a directory: ");
		ft_putendl(str);
		return (0);
	}
	stat(str, &r.buf);
	if (!S_ISDIR(r.buf.st_mode))
	{

		ft_putstr("ch_dir: no such file or directory: ");
		ft_putendl(str);
		return (0);
	}
	chdir(str);
	setpwd(envp);
	return (1);
}
