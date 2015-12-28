/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 01:03:56 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/19 17:52:03 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		convert_list(termi *list)
{
	termi	*tmp;
	char	c;

	c = 'A';
	while (list)
	{
		tmp = list->next;
		put_to_top(list, 0);
		put_to_left(list, 0);
		put_to_alphabet(list, c);
		c++;
		list = tmp;
	}
}

char		put_to_top(termi *list, int ok)
{
	if (list->piece[0] == '.' && list->piece[1] == '.' &&
			list->piece[2] == '.' && list->piece[3] == '.')
	{
		up_once(list->piece);
	}
	if (list->piece[0] == '#' || list->piece[1] == '#' ||
			list->piece[2] == '#' || list->piece[3] == '#')
		ok = 1;
	if (ok == 1)
		return (*list->piece);
	put_to_top(list, ok);
	return (*list->piece);
}

char		*up_once(char *tmp)
{
	tmp[0] = tmp[5];
	tmp[1] = tmp[6];
	tmp[2] = tmp[7];
	tmp[3] = tmp[8];
	tmp[5] = tmp[10];
	tmp[6] = tmp[11];
	tmp[7] = tmp[12];
	tmp[8] = tmp[13];
	tmp[10] = tmp[15];
	tmp[11] = tmp[16];
	tmp[12] = tmp[17];
	tmp[13] = tmp[18];
	tmp[15] = '.';
	tmp[16] = '.';
	tmp[17] = '.';
	tmp[18] = '.';
	return (tmp);
}

char		put_to_left(termi *list, int ok)
{
	if (list->piece[0] == '.' && list->piece[5] == '.' &&
			list->piece[10] == '.' && list->piece[15] == '.')
		left_once(list->piece);
	if (list->piece[0] == '#' || list->piece[5] == '#' ||
			list->piece[10] == '#' || list->piece[15] == '#')
		ok = 1;
	if (ok == 1)
		return (*list->piece);
	put_to_left(list, ok);
	return (*list->piece);
}

char		*left_once(char *tmp)
{
	tmp[0] = tmp[1];
	tmp[5] = tmp[6];
	tmp[10] = tmp[11];
	tmp[15] = tmp[16];
	tmp[1] = tmp[2];
	tmp[6] = tmp[7];
	tmp[11] = tmp[12];
	tmp[16] = tmp[17];
	tmp[2] = tmp[3];
	tmp[7] = tmp[8];
	tmp[12] = tmp[13];
	tmp[17] = tmp[18];
	tmp[3] = '.';
	tmp[8] = '.';
	tmp[13] = '.';
	tmp[18] = '.';
	return (tmp);
}
