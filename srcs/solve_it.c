/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:48:05 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/09 21:35:59 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve_it(int ***diez)
{
	int			map_size;
	char		*map_str;
	int			*ok;

	map_size = map_first_size(diez) - 1;
	while (42)
	{
		map_size++;
		map_str = map_build(map_size);
		ok = ok_build(diez);
		if (fillit(map_str, ok, diez, map_size))
		{
			free(map_str);
			break ;
		}
		free(map_str);
	}
}

int		fillit(char *map_str, int *ok, int ***diez, int map_size)
{
	int			i;
	size_t		j;
	size_t		len;

	if (ok[0] == -1)
	{
		free(ok);
		printf("%s\n", map_str);
		return (1);
	}
	i = 0;
	j = 0;
	len = ft_strlen(map_str);
	while (ok[i] > -1)
	{
		while (j <= len)
		{
			if (map_insert(map_str, diez[ok[i]], map_size, &j))
			{
				if (fillit(map_str, ok_remove(ok, ok[i]), diez, map_size))
				{
					free(ok);
					return (1);
				}
				else
					map_remove(map_str, diez[ok[i]], map_size, &j);
			}
			j++;
		}
		i++;
	}
	free(ok);
	return (0);
}