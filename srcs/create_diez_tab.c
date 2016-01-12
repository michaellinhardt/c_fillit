/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_diez_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:01:52 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/11 15:09:34 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		***create_diez_tab(char **tab)
{
	int		***diez;
	int		i;

	diez = NULL;
	i = 0;
	while (tab[i])
		i++;
	diez = (int ***)malloc(sizeof(int **) * (i + 1));
	i = 0;
	while (tab[i])
	{
		diez[i] = found_coord(tab[i], diez[i]);
		diez[i] = set_letter(diez[i]);
		i++;
	}
	diez[i] = (int **)NULL;
	return (diez);
}

int		**found_coord(char *tab, int **diez)
{
	int i;
	int j;
	int line;
	int row;

	i = -1;
	j = 0;
	line = 0;
	row = 0;
	diez = (int **)malloc(sizeof(int *) * 5);
	while (tab[++i])
	{
		if (tab[i] == '#')
		{
			diez[j] = (int *)malloc(sizeof(int) * 3);
			diez[j][0] = line;
			diez[j][1] = row;
			diez[j][2] = 'A';
			j++;
		}
		line_counter(&line, &row, tab[i]);
		row++;
	}
	diez[4] = (int *)NULL;
	return (diez);
}

void	line_counter(int *line, int *row, char c)
{
	if (c == '\n')
	{
		*line += 1;
		*row = -1;
	}
}

int		**set_letter(int **diez)
{
	static char c;

	c = (!c) ? (int)'A' : c + 1;
	diez[0][2] = (int)c;
	diez[1][2] = (int)c;
	diez[2][2] = (int)c;
	diez[3][2] = (int)c;
	return (diez);
}
