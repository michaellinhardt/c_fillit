/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:10:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/04 20:42:31 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_first_size(char **tab)
{
	int		nb_pieces;
	int		racine;

	nb_pieces = -1;
	while (tab[++nb_pieces])
		;
	nb_pieces *= 4;
	racine = 1;
	while ((racine * racine) < nb_pieces && racine++)
		;
	return (racine);
}

char	*map_build(int map_size)
{
	char	*map_str;
	int		newline;

	map_size = map_size * 4 + 4;
	map_str = ft_strnew((map_size + 1));
	newline = 5;
	map_str[map_size] = '\0';
	while(map_size > -1 && map_size--)
	{
		map_str[map_size] = (newline == 5) ? '\n' : '.' ;
		newline = (newline > 4) ? 1 : newline + 1 ;
	}
	return (map_str);
}