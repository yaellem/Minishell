#include <stdio.h>

int		main(void)
{
	char	*str;
	int		i;
	
	i = 1;
	str = "123456";
	printf("%s\n", &str[i - 1]);
	return (0);
}
