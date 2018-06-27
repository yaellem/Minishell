#include "minishell.h"

int		ch_dir(const char *str)
{
	t_read r;

	if (!str) 
	{
		ft_putendl("empty arg");
		chdir("$HOME");
	}
	else
	{
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
	}
	return (1);

}