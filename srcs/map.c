/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:15:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/05 03:37:58 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			map_first_size(char **tab)
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

char		*map_build(int map_size)
{
	char	*map_str;
	int		newline;
	int		newline_count;

	newline = map_size + 1;
	newline_count = newline;
	map_size = map_size * map_size + map_size;
	map_str = ft_strnew((map_size));
	map_str[map_size] = '\0';
	while(map_size > -1 && map_size--)
	{
		map_str[map_size] = (newline_count == newline) ? '\n' : '.' ;
		newline_count = (newline_count == newline) ? 1 : newline_count + 1 ;
	}
	return (map_str);
}
