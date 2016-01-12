/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/12 07:24:36 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_it(int ***diez)
{
	int		map_size;
	char	*map_str;

	map_size = map_first_size(diez) - 1;
	while (42)
	{
		map_size++;
		map_str = map_build(map_size);
		if (fillit(map_str, 0, diez, map_size))
			break ;
		free(map_str);
	}
	printf("%s\n", map_str);
	free(map_str);
}

char	fillit(char *map_str, int t, int ***diez, int map_size)
{
	size_t		pos;
	size_t		len;

	if (!diez[t])
		return (1);
	pos = 0;
	len = ft_strlen(map_str);
	while (pos < len)
	{
		if (too_heigh(diez[t], pos, map_size))
			return (0);
		if (too_width(diez[t], pos, map_size))
			{
				while(map_str[pos] != '\n')
					pos++;
				pos++;
				continue ;
			}
		if (map_insert(map_str, diez[t], map_size, pos))
		{
			if (fillit(map_str, (t + 1), diez, map_size))
				return (1);
			else
				map_remove(map_str, diez[t], map_size, pos);
		}
		pos++;
	}
	return (0);
}