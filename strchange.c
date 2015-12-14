#include <stdio.h>
#include <string.h>

char		put_to_top(char *str, int ok);
char	*up_once(char *tmp);
char	*left_once(char *tmp);
char		put_to_left(char *str, int ok);

int		main(void)
{
	char *str;
	char *tmp;
	int i;

	i = 0;
	str = "....\n....\n..##\n..##\n";

	tmp = strdup(str); 	
	printf("original :\n%s\n", tmp);
	put_to_top(tmp, 0);	
	printf("put_to_top :\n%s\n", tmp);
	put_to_left(tmp, 0);
	printf("put_to_left :\n%s\n", tmp);
	return (0);
}

char		put_to_top(char *tmp, int ok)
{
	if (tmp[0] == '.' && tmp[1] == '.' && tmp[2] == '.' && tmp[3] == '.')
	{
		up_once(tmp);
	}
	if (tmp[0] == '#' || tmp[1] == '#' || tmp[2] == '#' || tmp[3] == '#')
		ok = 1;
	if (ok == 1)
		return (*tmp);

	put_to_top(tmp, ok);
	return (0);
}

char	*up_once(char *tmp)
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

char		put_to_left(char *tmp, int ok)
{
	if (tmp[0] == '.' && tmp[5] == '.' && tmp[10] == '.' && tmp[15] == '.')
	{
		left_once(tmp);
	}
	if (tmp[0] == '#' || tmp[5] == '#' || tmp[10] == '#' || tmp[15] == '#')
		ok = 1;
	if (ok == 1)
		return (*tmp);

	put_to_left(tmp, ok);
	return (0);
}

char	*left_once(char *tmp)
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
