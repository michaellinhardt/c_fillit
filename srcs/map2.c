/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:15:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/12 12:24:27 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			map_insert(char *map_str, int **diez, int map_size, size_t i)
{
	int check_pos;
	int len;

	len = (ft_strlen(map_str) - 2);
	if (map_str[i] && map_str[i] != '\n')
	{
		check_pos = calc_check_pos(i, diez[0][0], diez[0][1], map_size);
		if (check_pos > len || map_str[check_pos] != '.')
			return (0);
		check_pos = calc_check_pos(i, diez[1][0], diez[1][1], map_size);
		if (check_pos > len || map_str[check_pos] != '.')
			return (0);
		check_pos = calc_check_pos(i, diez[2][0], diez[2][1], map_size);
		if (check_pos > len || map_str[check_pos] != '.')
			return (0);
		check_pos = calc_check_pos(i, diez[3][0], diez[3][1], map_size);
		if (check_pos > len || map_str[check_pos] != '.')
			return (0);
		put_piece_on_map(map_str, diez, i, map_size);
		return (1);
	}
	return (0);
}

int			too_heigh(int **diez, int pos, int map_size)
{
	int line;

	line = (pos / (map_size + 1));
	if ((diez[0][4] + line) > map_size)
		return (1);
	return (0);
}

int			too_width(int **diez, size_t *pos, int map_size, char *map_str)
{
	int row;

	row = (*pos % (map_size + 1));
	if ((diez[0][3] + row) > map_size)
	{
		while (map_str[*pos] != '\n')
			*pos += 1;
		*pos += 1;
		return (1);
	}
	return (0);
}
