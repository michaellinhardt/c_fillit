/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:10:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/05 10:20:41 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_it(char **tab)
{
	int			map_size;
	char		*map_str;
	int			*ok;
	t_mapsnap	*mapsnap;

	map_size = map_first_size(tab) - 1;
	while (42)
	{
		map_size++;
		map_str = map_build(map_size);
		ok = ok_build(tab);
		mapsnap = snapit((t_mapsnap *)NULL, ok, map_str, -1);
		if (loop_mapsnap(mapsnap, tab))
			break ;
		free_mapsnap(mapsnap);
		break ;
	}
}

int		loop_mapsnap(t_mapsnap *mapsnap, char **tab)
{
	int			i;
	char		*map_new;

	i = 0;
	while (mapsnap->ok[i] != -1)
	{
		if ((map_new = map_insert(mapsnap->map_str, tab[mapsnap->ok[i]])))
			loop_mapsnap(snapit(mapsnap, ok_remove(mapsnap->ok, mapsnap->ok[i]), map_new, mapsnap->ok[i]), tab);
		i++;
	}
	return (0);
}
