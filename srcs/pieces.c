/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 22:55:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/04 23:25:50 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					*ok_build(char **tab)
{
	int		*ok;
	int		i;

	i = 0;
	while (tab[i])
		i++;

	ok = (int *)malloc(sizeof(int) * i + 1);
	ok[i] = -1;
	while (i > -1 && i--)
		ok[i] = i;
	return (ok);
}

int					*ok_remove(int *ok, int remove)
{
	ok++;
	remove++;
	return (ok);
}