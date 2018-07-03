#include "minishell.h"

int main(int ac, char **av, char **env)
{
	//pid_t	pid;
	char	*line;
	char	**nwav;
	//char	**nwenv;

	(void)ac;
	(void)av;
	//nwenv = envrmt(env);
	ft_putstr("$> ");
	while (get_next_line(0, &line))
	{
//	print_tab_a(env);
		nwav = ft_strsplit(line, ' ');
		if (nwav[0] && ft_strcmp(nwav[0], "exit") == 0)
			nwav[1] ? exit(ft_atoi(nwav[1])) : exit(0);
		if (nwav[0] && ft_strcmp(nwav[0], "cd") == 0)
			ch_dir(nwav[1], env);
		if (nwav[0] && ft_strcmp(nwav[0], "pwd") == 0)
			pwd(nwav);
		free(line);
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
	return (0);
}
