/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 18:42:12 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/16 18:51:35 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	put_to_alphabet(termi *list, char c)
{
	int i;

	i = 0;
	while (list->piece[i])
	{
		if (list->piece[i] == '#')
			list->piece[i] = c;
		i++;
	}
	return (*list->piece);
}
