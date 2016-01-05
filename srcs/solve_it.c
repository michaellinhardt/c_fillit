/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:10:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/05 03:46:53 by mlinhard         ###   ########.fr       */
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
	mapsnap->last++;
	tab++;
	printf("ready to work\n");
	return (0);
}