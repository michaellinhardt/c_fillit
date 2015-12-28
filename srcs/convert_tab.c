#include "fillit.h"

void		convert_tab(char **tab)
{
	char	c;
	int		i;

	c = 'A';
	i = 0;
	while (tab[i])
	{
		put_to_top_tab(tab[i], 0);
		put_to_left_tab(tab[i], 0);
		put_to_alphabet_tab(tab[i], c);
		c++;
		i++;
	}
}

char		put_to_top_tab(char *str, int ok)
{
	if (str[0] == '.' && str[1] == '.' &&
			str[2] == '.' && str[3] == '.')
	{
		up_once_tab(str);
	}
	if (str[0] == '#' || str[1] == '#' ||
			str[2] == '#' || str[3] == '#')
		ok = 1;
	if (ok == 1)
		return *(str);
	put_to_top_tab(str, ok);
	return *(str);
}

char		*up_once_tab(char *tmp)
{
	tmp[0] = tmp[5];
	tmp[1] = tmp[6];
	tmp[2] = tmp[7];
	tmp[3] = tmp[8];
	tmp[5] = tmp[10];
	tmp[6] = tmp[11];
	tmp[7] = tmp[12];
	tmp[8] = tmp[13];
	tmp[10] = tmp[15];
	tmp[11] = tmp[16];
	tmp[12] = tmp[17];
	tmp[13] = tmp[18];
	tmp[15] = '.';
	tmp[16] = '.';
	tmp[17] = '.';
	tmp[18] = '.';
	return (tmp);
}

char		put_to_left_tab(char *str, int ok)
{
	if (str[0] == '.' && str[5] == '.' &&
			str[10] == '.' && str[15] == '.')
		left_once_tab(str);
	if (str[0] == '#' || str[5] == '#' ||
			str[10] == '#' || str[15] == '#')
		ok = 1;
	if (ok == 1)
		return *(str);
	put_to_left_tab(str, ok);
	return *(str);
}

char		*left_once_tab(char *tmp)
{
	tmp[0] = tmp[1];
	tmp[5] = tmp[6];
	tmp[10] = tmp[11];
	tmp[15] = tmp[16];
	tmp[1] = tmp[2];
	tmp[6] = tmp[7];
	tmp[11] = tmp[12];
	tmp[16] = tmp[17];
	tmp[2] = tmp[3];
	tmp[7] = tmp[8];
	tmp[12] = tmp[13];
	tmp[17] = tmp[18];
	tmp[3] = '.';
	tmp[8] = '.';
	tmp[13] = '.';
	tmp[18] = '.';
	return (tmp);
}
