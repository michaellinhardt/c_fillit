/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:10:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/04 22:39:10 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_it(char **tab)
{
	int		map_size;
	char	*map_str;

	map_size = map_first_size(tab) - 1;
	while (42)
	{
		map_size++;
		map_str = map_build(map_size);

		printf("Map size  : %d\n", map_size);
		printf("Map empty : ->\n%s", map_str);

		break ;
	}
}