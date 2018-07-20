#include "minishell.h"

int main(int ac, char **av, char **env)
{
	pid_t	pid;
	char	*line;
	char	***nwav;
	char	**nwenv;
	int		x;
	int i;

	x = 0;
	i = 0;
	(void)ac;
	(void)av;
	ft_putstr("$> ");
	nwenv= envrmt(env);
	while (get_next_line(0, &line))
	{
		nwav = NULL;
		if (line[0] != '\0')
			nwav = virgule_point(line);
		while (nwav != NULL  && nwav[x])
		{
			//trim_quote(&nwav[x]);
			while (nwav[x][i])
			{
				nwav[x][i] = dollar(nwav[x][i], nwenv);
				i++;
			}
			i = 0;
			if ((builtin_gestion(nwav[x], &nwenv)) == -1)
			{
				pid = fork();
				if (pid == 0)
				{
					if (execve(nwav[x][0], nwav[x], nwenv) == -1)
					{
						if (execve(getpath(nwav[x], get_line(nwenv)), nwav[x], nwenv)
							== -1)
						{	perror("");
					
							ft_putendl("Command not found");
						}
					}
				}
				else
					wait(NULL);
			}
			ft_freetab(nwav[x]);
			x++;
		}
		x = 0;
		free(line);
		ft_putstr("$> ");
	}
	return (0);
}
