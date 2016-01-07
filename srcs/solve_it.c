/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:10:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/07 10:33:09 by mlinhard         ###   ########.fr       */
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
		if ((map_new = map_insert(mapsnap->map_str, tab[mapsnap->ok[i]])))
			if (loop_mapsnap(snapit(mapsnap, ok_remove(mapsnap->ok, mapsnap->ok[i]), map_new, mapsnap->ok[i]), tab))
				return (1);
		i++;
	}
	return (0);
}
