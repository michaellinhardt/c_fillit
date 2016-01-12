/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:15:07 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/12 01:56:12 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_remove(char *map_str, int **diez, int map_size, size_t i)
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
