#include <stdio.h> 


int main(void)
{
	char *str;
	char *str2;
	int bit;
	int bit2;
	int bit_index;
	char *number;

	str = 	 ". . . . n # # # # n  .  .  .  .  n  .  .  .  .  n";
	number = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20";
	str2 = "##..\n#...\n#...\n....\n";
	bit_index = 160;
	while (*str)
	{
		//while (--bit_index >= 0)
		//{
		//	bit = *str >> bit_index & 1;
		//	printf("%d", bit);
		//}
		printf("%c", *str);
		str++;
	}
	printf("\n");
	printf("%s", number);
	printf("\n");
	bit_index = sizeof(*str2)*8-1;
	while (*str2)
	{
		while (--bit_index >= 0)
		{
			bit2 = *str2 >> bit_index & 1;
			printf("%d", bit2);
		}
		str2++;
	}
return (0);
}
