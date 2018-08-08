#include "minishell.h"

void	print_tab_a(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putendl(str[i++]);
	}
}
