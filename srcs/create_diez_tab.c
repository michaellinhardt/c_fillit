/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_diez_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:01:52 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/12 05:58:06 by mlinhard         ###   ########.fr       */
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
		diez[i] = set_size(diez[i]);
		i++;
	}
	diez[i] = (int **)NULL;
	return (diez);
}

int		**set_size(int **diez)
{
	int i;
	int width;
	int heigh;

	width = 0;
	heigh = 0;
	i = 0;
	while (diez[i])
	{
		width = (diez[i][1] > width) ? diez[i][1] : width;
		heigh = (diez[i][0] > heigh) ? diez[i][0] : heigh;
		i++;
	}
	diez[0][3] = (width + 1);
	diez[0][4] = (heigh + 1);
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
			diez[j] = (int *)malloc(sizeof(int) * 5);
			diez[j][0] = line;
			diez[j][1] = row;
			diez[j][2] = 'A';
			diez[j][3] = 0;
			diez[j][4] = 0;
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
