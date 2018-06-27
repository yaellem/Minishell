#include "minishell.h"

int main(int ac, char **av, char **env)
{
	//pid_t	pid;
	char	**nwav;

	nwav = NULL;
	(void)ac;
	(void)env;
	while (42)
	{
		ft_putstr("$> ");
		while ((get_next_line(0, av)))
		{
			nwav = ft_strsplit(av[0], ' ');
			if (nwav[0] && ft_strcmp(nwav[0], "exit") == 0)
				exit(0);
			if (nwav[0] && ft_strcmp(nwav[0], "cd") == 0)
				ch_dir(nwav[1]);
			if (nwav[0] && ft_strcmp(nwav[0], "pwd") == 0)
				pwd(nwav);
			ft_freetab(nwav);
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
		break ;
	 }
	return (0);
}
