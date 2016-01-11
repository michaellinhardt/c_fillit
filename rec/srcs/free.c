/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 17:40:39 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/09 18:50:50 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

void		free_diez(int ***diez)
{
	int		i;
	int		j;

	i = -1;
	while (diez[++i])
	{
		j = -1;
		while (diez[i][++j])
		{
			free(diez[i][j]);
			diez[i][j] = NULL;
		}
		free(diez[i]);
		diez[i] = NULL;
	}
	free(diez);
	diez = NULL;
}