/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:52:53 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/16 01:03:18 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_file(char *buf, int ret)
{
	int line;
	int char_nb;
	int pieces;

	line = 0;
	char_nb = 0;
	pieces = 0;
	if ((pieces = check_char_and_format(buf, line, char_nb, pieces)) == -1)
		return (1);
	pieces++;
	if (check_map(ret, pieces) == 1)
		return (1);
	return (0);
}

int		check_char_and_format(char *buf, int line, int char_nb, int pieces)
{
	int		i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (-1);
		if (line == 4 && char_nb == 20)
		{
			line = -1;
			char_nb = -1;
			pieces++;
		}
		if (buf[i] == '\n')
			line++;
		char_nb++;
	}
	return (pieces);
}

int		check_map(int ret, int pieces)
{
	if (ret <= 419 && pieces != (ret / 20))
		return (1);
	if (ret > 419 && pieces != ((ret / 20) - 1))
		return (1);
	return (0);
}

int		check_termi(char *buf)
{
	int i;
	int valid;

	valid = 0;
	i = 0;
	while (buf[i])
	{
		if (valid == 4)
			valid = 0;
		if (buf[i] == '#' && (buf[i + 1] == '#' ||
					buf[i - 1] == '#' ||
					buf[i - 5] == '#' ||
					buf[i + 5] == '#')) 
			valid++;
		i++;
	}
	if (valid != 0)
		return (1);
	return (0);
}
