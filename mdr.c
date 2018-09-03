int		is_char(char *str, char c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == c)
			j = 1;
	}
	return (j);
}

char	*dollar(char*str, char **envp)
{
	char	*dst;
	char	*tmp;
	char	**tmp2;
	char	**tab;
	char	*dup;
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	tab = ft_strsplit(str, '$');
	while (tab[x])
	{
		tmp = trim(tab[x]);
		while (envp[i])
		{
			y = 1;
			tmp2 = ft_strsplit(envp[i], '=');
			if (ft_strcmp(tmp2[0], tmp) == 0)
			{
				if (x == 0)
					dst = ft_strdup(tmp2[0]);
				else
					dst = ft_strjoin(dst, tmp2[0]);
				if (is_char(tab[x], '/'))
				{
					dup = ft_strinddup(tab[x], '/');	
					dst = ft_strjoin(dst, dup);
					free(dup);
				}
			}
			ft_freetab(tmp2);
			i++;
		}
		if (y == 0)
		{
			if (x == 0)

		}
		free(tmp);;
		x++;
	}
	return (dst);
}
