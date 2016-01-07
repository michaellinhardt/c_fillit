/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:10:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/07 19:26:36 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_it(int ***diez)
{
	int			map_size;
	char		*map_str;
	int			*ok;
	t_mapsnap	*mapsnap;

	map_size = map_first_size(diez) - 1;
	while (42)
	{
		map_size++;
		map_str = map_build(map_size);
		ok = ok_build(diez);
		mapsnap = snapit((t_mapsnap *)NULL, ok, map_str, -1);
		if (loop_mapsnap(mapsnap, diez, map_size))
			break ;
		free_mapsnap(mapsnap);
		break ;
	}
}

int		loop_mapsnap(t_mapsnap *mapsnap, int ***diez, int map_size)
{
	int			i;
	char		*map_new;
	static int	id;	if (!id) id = 0; id++; // debuging

	print_snap(mapsnap, id);

	if (mapsnap->ok[0] == -1)
	{
		printf("\nRIEN A POSER !!\n");
		return 1;
	}

	i = 0;
	while (mapsnap->ok[i] != -1)
	{
		if ((map_new = map_insert(mapsnap->map_str, diez[mapsnap->ok[i]], map_size)))
			if (loop_mapsnap(snapit(mapsnap, ok_remove(mapsnap->ok, mapsnap->ok[i]), map_new, mapsnap->ok[i]), diez, map_size))
				return (1);
		i++;
	}
	return (0);
}
