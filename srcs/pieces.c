/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 22:55:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/07 18:31:53 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ok_build(int ***diez)
{
	int		*ok;
	int		i;

	i = 0;
	while (diez[i])
		i++;

	ok = (int *)malloc(sizeof(int) * i + 1);
	ok[i] = -1;
	while (i > -1 && i--)
		ok[i] = i;
	return (ok);
}

int		*ok_remove(int *ok, int piece)
{
	int		i;
	int		j;
	int		*ok_new;

	i = 0;
	while (ok[i] != -1)
		i++;
	if (!(ok_new = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	ok_new[i] = -1;
	i = 0;
	j = 0;
	while (ok[j] > -1)
	{
		if (ok[i] != piece)
		{
			ok_new[j] = ok[i];
			j++;
		}
		i++;
	}
	return (ok_new);
}
