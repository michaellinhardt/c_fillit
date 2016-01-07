/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_diez_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:01:52 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/07 14:10:57 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**found_coord(char *tab, int **diez);

int		***create_diez_tab(char **tab)
{
	int		***diez;
	int		i;
	
	i = 0;
	while (tab[i])
		i++;
	*diez = (int **)malloc(sizeof(int) * i);
	i = 0;
	while (tab[i])
	{
		diez[i] = found_coord(tab[i], diez[i]);
		i++;
	}
	return (diez);
}

int		**found_coord(char *tab, int **diez)
{
	int i;
	int line;
	int row;
	int j;
	int k;
	
	line = 0;
	row = 0;
	*diez = (int *)malloc(sizeof(int) * 4);
	while (tab[i])
	{
		if (tab[i] == '#')
		{
			*diez[j] = (int)malloc(sizeof(int) * 2);
			diez[j][0] = line;
			diez[j][1] = row;
			j++;
		}
		if (tab[i] == '\n')
		{
			line++;
			row = 0;
		}
		i++;
		row++;
	}
	return (diez);
}
