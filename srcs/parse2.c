/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 17:40:39 by mconnat           #+#    #+#             */
/*   Updated: 2016/01/13 16:34:59 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ret_len(char *buf, int *line)
{
	int i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
			*line += 1;
	}
}

void		check_ret(int line, int len)
{
	if (((len * 5) - 1) != line)
		call_error(8);
}

int			check_tetri(char *buf, int i, int diez, int dot)
{
	int valid;
	int valid2;

	valid = 0;
	valid2 = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			diez++;
		if (buf[i] == '.')
			dot++;
		check_connect_tetri(buf, i, &valid2, &valid);
		if (buf[i] == '#' && valid == 0)
			return (1);
		i++;
	}
	if (dot != 12 || diez != 4)
		call_error(1);
	if (valid == 4 && valid2 > 5)
		return (0);
	return (-1);
}

void		check_connect_tetri(char *buf, int i, int *valid2, int *valid)
{
	if (buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
		call_error(6);
	if (buf[i] == '#' && (buf[i + 1] == '#' || buf[i - 1] == '#' ||
				buf[i - 5] == '#' || buf[i + 5] == '#'))
		*valid += 1;
	if (buf[i] == '#')
	{
		if (buf[i + 1] == '#')
			*valid2 += 1;
		if (buf[i - 1] == '#')
			*valid2 += 1;
		if (buf[i - 5] == '#')
			*valid2 += 1;
		if (buf[i + 5] == '#')
			*valid2 += 1;
	}
}
