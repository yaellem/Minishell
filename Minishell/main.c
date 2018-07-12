#include "minishell.h"

int main(int ac, char **av, char **env)
{
	//pid_t	pid;
	char	*line;
	char	***nwav;
	char	**nwenv;
	int		x;

	x = 0;
	(void)ac;
	(void)av;
	ft_putstr("$> ");
	nwenv = envrmt(env);
	while (get_next_line(0, &line))
	{
		nwav = NULL;
		if (line[0] != '\0')
			nwav = virgule_point(line);
		while (nwav != NULL  && nwav[x])
		{
		/*	if (nwav[x][0] && ft_strcmp(nwav[x][0], "exit") == 0)
				nwav[x][1] ? exit(ft_atoi(nwav[x][1])) : exit(0);
			if (nwav[x][0] && ft_strcmp(nwav[x][0], "cd") == 0)
				ch_dir(nwav[x][1], env);
			if (nwav[x][0] && ft_strcmp(nwav[x][0], "pwd") == 0)
				pwd(nwav[x]);*/
			builtin_gestion(nwav[x], &nwenv);
			ft_freetab(nwav[x]);
			x++;
		}
		x = 0;
		//ft_freetrtab(nwav);
		free(line);
		ft_putstr("$> ");
		// pid = fork();
		// if (pid == 0)
		// {	
		// 	pid = fork();
		// 	if (pid == 0)
		// 		execve(*av, av + 1, env);
		// 	else
		// 		wait(NULL);
		// 	ft_putstr("$> ");
		// }
		// else
		// {
		// 	kill(pid, 0);
		// }
	}
	return (0);
}
