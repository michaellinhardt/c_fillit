/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 12:01:03 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/04 17:49:07 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	free_int_array(int *tab, int len);

int		count_piece_table(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		*create_int_array(char **tab)
{
	int max;
	int min;
	int *piece;
	int i;

	i = 0;
	min = 0;
	max = count_piece_table(tab);
	piece = (int *)malloc(sizeof(int) * (max - min));
	while (i < max)
	{
		piece[i] = min;
		min++;
		i++;
	}
	return (piece);
}

int		*delete_piece(int *piece, int pos, int len)
{
	int	*tmp;
	int i;
	int found;
	int j;

	j = 0;
	found = 0;
	i = 0;
	while (i < len)
	{
		if (piece[i] == pos)
		{
			piece[i] = 27;
			found = 1;
		}
		i++;
	}
	if (found == 1)
	{
		if (!(tmp = (int *)malloc(sizeof(int) * (i - 1))))
			return (NULL);
		i = 0;
		while (i < len)
		{
			if (piece[i] == 27)
				i++;	
			tmp[j] = piece[i];
			i++;
			j++;
		}
		return (tmp);
	}
	return (piece);
}

int		main(void)
{
	char **tab;
	int *piece;
	char *str;
	int i;
	int j;
	int pos = 4;
	int len;
	char *map;

	i = 0;
	j = 0;
	str = "Bonjour*SALUT*SALU*HELLO*LOLOLOL*fsdf*sdfdsf*sdfsdf*sdfsdf*sdfsdf";
	tab = ft_strsplit(str, '*');
	while (tab[i])
	{
		printf("tab of string :%s\n", tab[i]);
		i++;
	}
	piece = create_int_array(tab);
	len = count_piece_table(tab);
	ft_ctabfree(tab);
	while (j < len )
	{
		printf("before del : %d\n", piece[j]);
		j++;
	}

	piece = delete_piece(piece, pos, len);
	j = 0;
	while (j < len - 1)
	{
		printf("after del : %d\n", piece[j]);
		j++;
	}
	return (0);
}
