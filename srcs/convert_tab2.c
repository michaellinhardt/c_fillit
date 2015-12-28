#include "fillit.h"

char	put_to_alphabet_tab(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = c;
		i++;
	}
	return *(str);
}
