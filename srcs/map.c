/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:15:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/12 12:25:06 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		map_remove(char *map_str, int **diez, int map_size, size_t i)
{
	int		check_pos;

	check_pos = calc_check_pos(i, diez[0][0], diez[0][1], map_size);
	map_str[check_pos] = '.';
	check_pos = calc_check_pos(i, diez[1][0], diez[1][1], map_size);
	map_str[check_pos] = '.';
	check_pos = calc_check_pos(i, diez[2][0], diez[2][1], map_size);
	map_str[check_pos] = '.';
	check_pos = calc_check_pos(i, diez[3][0], diez[3][1], map_size);
	map_str[check_pos] = '.';
}

int			map_first_size(int ***diez)
{
	int		nb_pieces;
	int		racine;

	nb_pieces = -1;
	while (diez[++nb_pieces])
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
	map_str = ft_strnew(map_size);
	map_str[map_size] = '\0';
	while (map_size > -1 && map_size--)
	{
		map_str[map_size] = (newline_count == newline) ? '\n' : '.';
		newline_count = (newline_count == newline) ? 1 : newline_count + 1;
	}
	return (map_str);
}

int			calc_check_pos(int i, int line, int row, int map_size)
{
	return (((line * (map_size + 1)) + row) + i);
}

char		*put_piece_on_map(char *map_str, int **diez, int i, int map_size)
{
	map_str[calc_check_pos(i, diez[0][0], diez[0][1],
			map_size)] = (char)(diez[0][2]);
	map_str[calc_check_pos(i, diez[1][0], diez[1][1],
			map_size)] = (char)(diez[1][2]);
	map_str[calc_check_pos(i, diez[2][0], diez[2][1],
			map_size)] = (char)(diez[2][2]);
	map_str[calc_check_pos(i, diez[3][0],
			diez[3][1], map_size)] = (char)(diez[3][2]);
	return (map_str);
}
