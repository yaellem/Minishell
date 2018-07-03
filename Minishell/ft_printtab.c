#include "minishell.h"

void	print_tab_a(char **str)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
	}
}
