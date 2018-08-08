#include "minishell.h"

char	**trim_quote(char **nwav)
{
	char	**dst;
	char	*line;
	int		dquote;
	int		quote;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	dquote = 0;
	quote = 0;
	dst = malloc(sizeof(char*) * (4096));
	while (nwav[i])
	{
		while (nwav[i][j])
		{
			if (nwav[i][j] == '\"' || nwav[i][j] == '\'')
			{
				if (nwav[i][j] == '\"')
					dquote++;
				else if (nwav[i][j] == '\'')
					quote++;
				j++;
			}
			dst[i] = malloc(sizeof(char) * (ft_strlen(nwav[i]) + 1));
			dst[i][k++] = nwav[i][j++];
		}
		dst[i][k] = '\0';
		k = 0;
		j = 0;
		i++;
	}
	dst[i] = NULL;
	ft_putstr("dquote>");
	if ((dquote % 2) != 0)
	{
		ft_putstr("dquote>");
		while (get_next_line(0, &line))
		{
			if (ft_is_here(line, '\"') == 0)
			{
				dst[i++] = ft_strndup(line, '\"');
				break;
			}
			dst[i++] = ft_strdup(line);
			ft_putstr("dquote>");
		}
		dst[i] = NULL;
		print_tab_a(dst);
		return (dst);
	}
	return (dst);

}
