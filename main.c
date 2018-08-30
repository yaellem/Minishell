#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_env	e;
	t_index	ind;

	ind.x = 0;
	ind.i = 0;
	ind.y = 0;
	(void)ac;
	(void)av;
	ft_putstr("$> ");
	e.nwenv= envrmt(env);
	while (get_next_line(0, &e.line))
	{
		e.nwav = NULL;
		e.str = NULL;
		if (e.line[0] != '\0')
			e.nwav = virgule_point(e.line);
		while (e.nwav != NULL  && e.nwav[ind.x])
		{
			while (e.nwav[ind.x][ind.i])
			{
				//e.freem = e.nwav[ind.x][ind.i];
				e.nwav[ind.x][ind.i] = dollar(e.nwav[ind.x][ind.i], e.nwenv);
				if (e.nwav[ind.x][ind.i] && e.nwav[ind.x][ind.i][0] == '~' && !e.nwav[ind.x][ind.i][1])
				{
					free(e.nwav[ind.x][ind.i]);
					e.nwav[ind.x][ind.i] = tilde(e.nwenv);
					ind.y = 1;
				}
				else if (e.nwav[ind.x][ind.i] && e.nwav[ind.x][ind.i][0] == '~' && e.nwav[ind.x][ind.i][1]
						== '/')
				{
					e.str = ft_strdup(e.nwav[ind.x][ind.i]);
					free(e.nwav[ind.x][ind.i]);
					e.nwav[ind.x][ind.i] = tilde(e.nwenv);
					if (e.str[2])
						e.nwav[ind.x][ind.i] = ft_strjoin(e.nwav[ind.x][ind.i],
						ft_strchr(e.str, '/'));
					else
						e.nwav[ind.x][ind.i] = ft_strjoin(e.nwav[ind.x][ind.i], "/") ;
					ind.y = 1;
				}
				else if (e.nwav[ind.x][ind.i] && e.nwav[ind.x][ind.i][0] == '~' && e.nwav[ind.x][ind.i][1]
						!= '/' && e.nwav[ind.x][ind.i][1] != '~' && e.nwav[ind.x][ind.i][1] != '-')
				{
					ft_putstr("minishell: no such user or named directory: ");
					ft_putendl(&e.nwav[ind.x][ind.i][1]);
				}	
				ind.i++;
			}
			if ((builtin_gestion(e.nwav[ind.x], &e.nwenv)) == -1)
				binary_gestion(e.nwav[ind.x], e.nwenv, e.str);
		//	ind.y != 1 ? ft_freetab(e.nwav[ind.x]) : 0;
			ft_freetab(e.nwav[ind.x]);
			ind.i = 0;
			ind.x++;
		}
		ind.x = 0;
		free(e.line);
		free(e.nwav);
		ft_putstr("$> ");
	}
	return (0);
}
