#include "fillit.h"

char	**create_tab2(char *buf, char **tab)
{
	int		i;
	int		line;

	i = -1;
	line = 0;
	while (buf[++i] != '\0')
	{
		if (buf[i] == '\n')
			line++;
		if (line == 5)
		{
			line = 0;
			buf[i] = '*';
		}
	}
	tab = ft_strsplit(buf, '*');
	return (tab);
}