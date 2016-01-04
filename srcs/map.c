/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:10:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/04 20:01:10 by mlinhard         ###   ########.fr       */
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