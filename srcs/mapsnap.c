/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsnap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 03:37:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/01/11 15:17:55 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mapsnap	*snapit(t_mapsnap *prev, int *ok, char *map_str, int last)
{
	static int	id;
	t_mapsnap	*newsnap;

	if (!id)
		id = 0;
	if (!(newsnap = (t_mapsnap *)ft_memalloc(sizeof(t_mapsnap))))
		return (NULL);
	newsnap->id = id++;
	newsnap->next = NULL;
	newsnap->prev = prev;
	newsnap->ok = ok;
	newsnap->map_str = map_str;
	newsnap->last = last;
	if (prev)
		prev->next = newsnap;
	return (newsnap);
}

void		free_mapsnap(t_mapsnap *mapsnap)
{
	t_mapsnap	*free_it;
	t_mapsnap	*test;

	test = mapsnap;
	while (mapsnap->next)
		mapsnap = mapsnap->next;
	while (mapsnap->prev)
	{
		free_it = mapsnap;
		mapsnap = mapsnap->prev;
		free_this_snap(free_it);
	}
	free_this_snap(mapsnap);
}

void		free_this_snap(t_mapsnap *free_it)
{
	free_it->id = (int)NULL;
	free_it->next = (t_mapsnap *)NULL;
	free_it->prev = (t_mapsnap *)NULL;
	free(free_it->ok);
	free_it->ok = NULL;
	free(free_it->map_str);
	free_it->map_str = NULL;
	free_it->last = (int)NULL;
	free(free_it);
	free_it = NULL;
}
