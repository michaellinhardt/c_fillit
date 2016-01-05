/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:10:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/05 03:28:39 by mlinhard         ###   ########.fr       */
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
		ok = ok_build(tab); map_str = map_build(map_size);
		mapsnap = snapit(mapsnap, ok, map_str, 0);
		ok = ok_build(tab); map_str = map_build(map_size);
		mapsnap = snapit(mapsnap, ok, map_str, 1);
		ok = ok_build(tab); map_str = map_build(map_size);
		mapsnap = snapit(mapsnap, ok, map_str, 2);
		ok = ok_build(tab); map_str = map_build(map_size);
		mapsnap = snapit(mapsnap, ok, map_str, 3);

		printf("Map size  : %d\n", map_size);
		printf("Map empty : ->\n%s", map_str);

		free_mapsnap(mapsnap);

		break ;
	}
}